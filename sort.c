#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "lib.h"

int compare(void *_a, size_t i, size_t j)
{
	int x = ((int *)_a)[i];
	int y = ((int *)_a)[j];

	if (x < y)    return -1;
	if (x > y)    return +1;
	return 0;
}

void exch(void *_a, size_t i, size_t j)
{
	int tmp;
	int *a = (int *)_a;

	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void copy(void *_dest, void *_src, size_t i, size_t j)
{
	int *dest = (int *)_dest;
	int *src = (int *)_src;

	dest[i] = src[j];
}


static bool selection_sort(void *array, size_t len, size_t item_sz,
			cmp_t cmp, exch_t exch, copy_t copy)
{
	size_t min;

	for(size_t i = 0; i < (len - 1); i++)
	{
		min = i;

		for(size_t j = i + 1; j < len; j++)
		{
			if (cmp(array, j, min) < 0)
				min = j;
		}

		exch(array, i, min);
	}

	return true;
}


static bool insertion_sort(void *array, size_t len, size_t item_sz,
			cmp_t cmp, exch_t exch, copy_t copy)
{
	for(size_t i = 0; i < (len - 1); i++)
	{
		for(size_t j = i + 1; j > 0; j--)
		{
			if (cmp(array, j, (j - 1)) < 0)
				exch(array, j, (j - 1));
			else
				break;
		}
	}

	return true;
}


static bool is_sorted(void *array, size_t lo, size_t hi, cmp_t cmp)
{
	for(size_t i = lo + 1; i <= hi; i++)
	{
		if (cmp(array, i, (i - 1)) < 0)
			return false;
	}

	return true;
}


static void merge(void *array, void *aux,
		size_t item_sz, size_t lo, size_t mid, size_t hi,
		cmp_t cmp, exch_t exch, copy_t copy)
{
	size_t i;
	size_t j;

	assert(is_sorted(aux, lo, mid, cmp));
	assert(is_sorted(aux, (mid + 1), hi, cmp));

	i = lo;
	j = mid + 1;
	for(size_t k = lo; k <= hi; k++)
	{
		if (i > mid)
		{
			copy(array, aux, k, j);
			j++;
		}
		else if (j > hi)
		{
			copy(array, aux, k, i);
			i++;
		}
		else
		{
			if (cmp(aux, j, i) < 0)
			{
				copy(array, aux, k, j);
				j++;
			}
			else
			{
				copy(array, aux, k, i);
				i++;
			}
		}
	}

	assert(is_sorted(array, lo, hi, cmp));
}


#define MERGE_SORT_CUTOFF 7
static void merge_sort_aux(void *array, void *aux,
			size_t item_sz, size_t lo, size_t hi,
			cmp_t cmp, exch_t exch, copy_t copy)
{

	size_t mid = (lo + hi) / 2;

	/* Insertion sort is faster for array 7 or fewer elements */
	if (hi <= (MERGE_SORT_CUTOFF + lo - 1))
	{
		void *_array = (char *)array + lo * item_sz;
		size_t len = hi - lo + 1;

		insertion_sort(_array, len, item_sz, cmp, exch, copy);
		assert(is_sorted(array, lo, hi, cmp));
		return;
	}

	merge_sort_aux(aux, array, item_sz, lo, mid, cmp, exch, copy);
	merge_sort_aux(aux, array, item_sz, mid + 1, hi, cmp, exch, copy);

	merge(array, aux, item_sz, lo, mid, hi, cmp, exch, copy);
}

static bool merge_sort(void *array, size_t len, size_t item_sz,
		cmp_t cmp, exch_t exch, copy_t copy)
{
	void *aux = NULL;

	if ((aux = malloc(len * item_sz)) == NULL)
	{
		logperror("malloc()");
		return false;
	}

	/* Copy array to auxillary array */
	memcpy(aux, array, item_sz * len);

	merge_sort_aux(array, aux, item_sz, 0, (len - 1), cmp, exch, copy);

	free(aux);
	aux = NULL;
	return true;
}

static size_t partition(void *array, size_t lo, size_t hi,
		cmp_t cmp, exch_t exch)
{
	size_t i, j;

	/* There should be 2 or more elements to proceed*/
	/* assert(lo < hi); */

	i = lo + 1;
	j = hi;
	while (true)
	{
		while (cmp(array, i, lo) < 0)
		{
			if (i == hi)
				break;
			i++;
		}

		while (cmp(array, j, lo) > 0)
		{
			if (j == lo)
				break;
			j--;
		}

		if (i >= j)
		{
			exch(array, j, lo);
			break;
		}

		exch(array, i, j);
		i++;
		j--;
	}

	return j;
}


static size_t median_of_3(void *array, size_t lo, size_t mid, size_t hi,
			cmp_t cmp)
{
	if (cmp(array, lo, mid) <= 0)
	{
		if (cmp(array, mid, hi) <= 0)
			return mid;
		else
			return hi;
	}
	else /* mid < lo */
	{
		if (cmp(array, lo, hi) <= 0)
			return lo;
		else
			return hi;
	}
}

#define QUICK_SORT_CUTOFF 10

static void quick_sort_aux(void *array, size_t lo, size_t hi,
		cmp_t cmp, exch_t exch)
{
	size_t p;

_restart:
	/* Insertion sort is faster for array size 10 or fewer elements. */
	/* The is done at the end, in one pass */
	if (hi <= (QUICK_SORT_CUTOFF + lo - 1))
		return;

	p = median_of_3(array, lo, (lo + hi) / 2, hi, cmp);
	exch(array, lo, p);

	p = partition(array, lo, hi, cmp, exch);

	/* assert(lo <= p); */
	/* assert(p <= hi); */

	if ((p - lo) <= (hi - p)) /* For tail call optmization */
	{
		if (lo < p) /* to avoid the case where p == 0 */
			quick_sort_aux(array, lo, (p - 1), cmp, exch);

		/* quick_sort_aux(array, (p + 1), hi, cmp, exch); */
		lo = p + 1;
		goto _restart;
	}
	else
	{
		quick_sort_aux(array, (p + 1), hi, cmp, exch);

		/* quick_sort_aux(array, lo, (p - 1), cmp, exch); */
		hi = (p - 1);
		goto _restart;
	}

	/* assert(is_sorted(array, lo, hi, cmp)); */
	return;
}

static bool quick_sort(void *array, size_t len, size_t item_sz,
		cmp_t cmp, exch_t exch, copy_t copy)
{

	shuffle(array, len, exch);
	quick_sort_aux(array, 0, (len - 1), cmp, exch);
	insertion_sort(array, len, item_sz, cmp, exch, copy);
	return true;
}


static void quick_sort_3way_aux(void *array, size_t lo, size_t hi,
				cmp_t cmp, exch_t exch)
{
	size_t lt = lo;
	size_t gt = hi;
	size_t i = lo;
	int cmp_result;

	if (lo >= hi)
		return;

	while (i <= gt)
	{
		cmp_result = cmp(array, i, lt);

		if (cmp_result < 0)
		{
			exch(array, i, lt);
			i++;
			lt++;
		}
		else if (cmp_result > 0)
		{
			exch(array, i, gt);
			gt--;
		}
		else
			i++;
	}


	if ((lt - lo) <= (hi - gt))
	{
		if (lo < lt) /* to account for lt != 0 */
			quick_sort_3way_aux(array, lo, (lt - 1), cmp, exch);
		quick_sort_3way_aux(array, (gt + 1), hi, cmp, exch);
	}
	else
	{
		quick_sort_3way_aux(array, (gt + 1), hi, cmp, exch);
		quick_sort_3way_aux(array, lo, (lt - 1), cmp, exch);
	}

}


static bool quick_sort_3way(void *array, size_t len, size_t item_sz,
		cmp_t cmp, exch_t exch, copy_t copy)
{
	shuffle(array, len, exch);
	quick_sort_3way_aux(array, 0, (len - 1), cmp, exch);
	/* insertion_sort(array, len, item_sz, cmp, exch, copy); */
	return true;
}


static size_t quick_select(void *array, size_t len, size_t k,
			cmp_t cmp, exch_t exch)
{
	size_t lo = 0;
	size_t hi = (len - 1);
	size_t p;

	assert((lo <= k) && (k <= hi));

	shuffle(array, len, exch);

	while(lo < hi)
	{
		p = partition(array, lo, hi, cmp, exch);

		if (k < p)
			hi = p - 1;
		else if (k > p)
			lo = p + 1;
		else /* k == p */
			return k;
	}

	assert(lo == hi);
	assert(lo == k);
	return lo;
}


static size_t heap_parent(size_t i)
{
	if (i == 0)
		return 0;

	return ((i - 1) / 2);
}

static size_t heap_left(size_t i)
{
	return (2 * i + 1);
}

static size_t heap_right(size_t i)
{
	return (heap_left(i) + 1);
}

static void swim(void *array, size_t k, cmp_t cmp, exch_t exch)
{
	size_t parent = heap_parent(k);

	while((k > 0) && (cmp(array, parent, k) < 0))
	{
		exch(array, parent, k);
		k = parent;
	}
}


static void sink(void *array, size_t heap_size, size_t i,
		cmp_t cmp, exch_t exch)
{
	size_t j;

	while(heap_left(i) <= (heap_size - 1))
	{
		j = heap_left(i);

		/*if there's a right child and that child is larger */
		if ((j < (heap_size - 1)) && (cmp(array, j + 1, j) > 0))
			j++;

		/* if parent is greater than child, we are done*/
		if (cmp(array, i, j) >= 0)
			break;

		exch(array, i, j);
		i = j;
	}
}


static bool heap_sort(void *array, size_t len, size_t item_sz,
		cmp_t cmp, exch_t exch, copy_t copy)
{
	/* Put the array in heap order */
	for(size_t i = heap_parent(len - 1); i > 0; i--)
		sink(array, len, i, cmp, exch);
	sink(array, len, 0, cmp, exch);


	while(len > 1)
	{
		exch(array, 0, (len - 1));
		len--;
		sink(array, len, 0, cmp, exch);
	}

	return true;
}

int array[1024 * 1024 * 32];

int main()
{
	size_t len = sizeof(array)/sizeof(array[0]);
	uint seed = 1;
	int ret = EXIT_SUCCESS;
	/* sort_t *sort_fns[] = {selection_sort, insertion_sort, merge_sort}; */
	/* sort_t *sort_fns[] = { quick_sort_3way }; */
        sort_t *sort_fns[] = { quick_sort };
	/* sort_t *sort_fns[] = { heap_sort }; */

	for(size_t i = 0; i < len; i++)
		array[i] = i;

	if (!initialize_random())
	{
		log("initialize_random()");
		goto cleanup;
	}

	/* for(size_t i = 0; i < sizeof(array)/sizeof(array[0]); i++) */
	/* 	printf("%d ", array[i]); */
	/* printf("\n"); */

#if 1
	for (size_t i = 0; i < sizeof(sort_fns)/sizeof(sort_fns[0]); i++)
	{
		if (!(     (sort_fns[i] == quick_sort)
			|| (sort_fns[i] == quick_sort_3way)))
			shuffle(array, len, exch);

		sort_fns[i](array, len, sizeof(int), compare, exch, copy);

		if (is_sorted(array, 0, (len - 1), compare))
			printf("sorted\n");
		else
			printf("not sorted\n");
	}

#else
	size_t k;
	size_t j;
	size_t x;

	k = (size_t) (random() % len);
	j = quick_select(array, len, k, compare, exch);
	x = (size_t) array[j];
	printf("x = %zu; k = %zu\n", x, k);
	assert(x == k);

#endif

cleanup:
	exit(ret);
}

