#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>

#include "lib.h"

typedef unsigned int uint;

typedef struct heap_t {
	size_t len;
	size_t n;
	size_t elt_sz;
	void   *a;
	/* size_t limit; */
} heap_t;


static void check_heap(heap_t *heap);

static void swim(heap_t *heap, size_t k, cmp_t cmp, exch_t exch)
{
	while((k > 1) && (cmp(heap->a, k/2, k) < 0))
	{
		exch(heap->a, k/2, k);
		k = k/2;
	}
}

static bool insert(heap_t *heap, void *elt,
		cmp_t cmp, exch_t exch, copy_elt_t copy_to_array)
{
#if 0
	/* printf("heap->len = %zu\n", heap->len); */
	if (heap->len == 0)
	{
		assert(heap->a == NULL);

		/*Since a[0] is not used ...*/
		if ((heap->a = malloc(heap->elt_sz * 2)) == NULL)
		{
			logperror("malloc()");
			return false;
		}

		heap->len = 2;
		heap->n = 0;
	}
	else if (heap->n == (heap->len - 1))
	{
		void *_a = NULL;
		size_t len = heap->len * 2;

		assert(heap->a != NULL);

		/* if ((heap->len * 2) > heap->limit) */
		/* 	return false; */

		if ((_a = realloc(heap->a, len * heap->elt_sz)) == NULL)

		{
			logperror("realloc()");
			return false;
		}

		heap->len = len;
		heap->a = _a;
	}
#endif

	if (heap->n >= (heap->len - 1))
		return false;

	heap->n++;
	copy_to_array(heap->a, heap->n, elt);
	swim(heap, heap->n, cmp, exch);

	return true;
}

static void sink(heap_t *heap, size_t i, cmp_t cmp, exch_t exch)
{
	size_t j;

	while((2 * i) <= heap->n)
	{
		j = 2 * i;

		/*if there's a right child and that child is larger */
		if ((j < heap->n) && (cmp(heap->a, j + 1, j) > 0))
			j++;

		/* printf("==> a[%zu] = %d, a[%zu] = %d\n", i, a[i], j, a[j]); */

		if (cmp(heap->a, i, j) >= 0)
			break;

		exch(heap->a, i, j);
		i = j;
	}
}


static bool del_max(heap_t *heap, void *max,
		cmp_t cmp, exch_t exch, copy_elt_t copy_from_array)
{
	/* printf("heap->len = %zu\n", heap->len); */
	if (heap->n < 1)
		return false;
#if 0
	if (heap->n < heap->len/4)
	{
		void *_a = NULL;
		size_t len = heap->len/2;

		if ((_a = realloc(heap->a, len * heap->elt_sz)) == NULL)
		{
			logperror("realloc()");
			return false;
		}

		heap->a = _a;
		heap->len = len;
	}
#endif
	/* check_heap(heap); */
	copy_from_array(heap->a, 1, max);
	exch(heap->a, 1, heap->n);
	heap->n--;
	/* printf("--> %d [--n; heap->n = %zu]\n", */
	/* 	*((int *)max), heap->n); */
	sink(heap, 1, cmp, exch);
	/* check_heap(heap); */
	return true;
}


static int cmp(void *_a, size_t i, size_t j)
{
	int *a = _a;
	int ret = 0;

	if (a[i] < a[j])
		ret = -1;
	else if (a[i] > a[j])
		ret = 1;
	else
		ret = 0;


	/* printf("cmp(%d, %d) = %d\n", a[i], a[j], ret); */
	return ret;
}

static void exch(void *_a, size_t i, size_t j)
{
	int *a = _a;
	int tmp;

	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
	return;
}

static void copy_from_array(void *_a, size_t i, void *_elt)
{
	int *a = _a;
	int *elt = _elt;

	*elt = a[i];
	return;
}

static void copy_to_array(void *_a, size_t i, void *_elt)
{
	int *a = _a;
	int *elt = _elt;

	a[i] = *elt;
	return;
}

static void check_heap(heap_t *heap)
{
	int *a = heap->a;
	size_t parent;
	size_t left;
	size_t right;

	for(size_t i = 1; i <= heap->n; i++)
	{
		/* printf("a[%zu] = %d ", i, a[i]); */

		parent = i / 2;
		left = i * 2;
		right = left + 1;

		/* if (parent >= 1) */
		/* 	printf("parent = %d ",	a[parent]); */
		/* if (left <= heap->n) */
		/* 	printf("left = %d ", a[left]); */
		/* if (right <= heap->n) */
		/* 	printf("right = %d", a[right]); */
		/* printf("\n"); */

		if (parent >= 1)
			assert(a[i] <= a[parent]);

		if (left <= heap->n)
			assert(a[i] >= a[left]);

		if (right <= heap->n)
			assert(a[i] >= a[right]);
 	}
	/* printf("\n"); */
}


#define ARRAY_LEN (1024 * 32)
int array[ARRAY_LEN];
int heap_array[ARRAY_LEN + 1];


int main()
{
	size_t len = sizeof(array)/sizeof(array[0]);
	int ret = EXIT_SUCCESS;
	heap_t heap = { .len = (ARRAY_LEN + 1),
			.elt_sz = sizeof(int),
			.n = 0,
			/* .limit = 16, */
			.a = heap_array };
	int elt = 0;

	if (!initialize_random())
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	for(size_t i = 0; i < len; i++)
		array[i] = i;

	shuffle(array, len, exch);

	for(size_t i = 0; i < len; i++)
	{
		/* printf("inserting %d\n", array[i]); */
		if (!insert(&heap, &array[i], cmp, exch, copy_to_array))
		{
			log("insert() failed");
			goto cleanup;
		}
		check_heap(&heap);
	}

	printf("finished insertion\n");

	/* List largest 4 elements */
	for(size_t i = 0; i < len; i++)
	{
		elt = 0;

		if (!del_max(&heap, &elt, cmp, exch, copy_from_array))
		{
			log("del_max() failed");
			printf("heap.n = %zu; heap.len = %zu; i = %zu\n",
				heap.n, heap.len, i);
			goto cleanup;
		}
		if (i < 4)
			printf("--> %d\n", elt);
		check_heap(&heap);
	}

cleanup:
#if 0
	if (heap.a != NULL)
	{
		free(heap.a);
		heap.a = NULL;
		heap.len = 0;
		heap.n = 0;
		heap.elt_sz = 0;
	}
#endif
	exit(ret);
}
