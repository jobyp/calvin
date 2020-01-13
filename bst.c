#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib.h"


typedef struct bst_node {
	void *key;
	void *value;
	struct bst_node *left;
	struct bst_node *right;
} bst_node_t;


void exch_int(void *_a, size_t i, size_t j)
{
	int tmp;
	int *a = (int *)_a;

	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}


int array[1024];

int main(void)
{
	int ret = EXIT_SUCCESS;

	if (!initialize_random())
	{
		log("initialize_random() failed");
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	shuffle(array, sizeof(array)/sizeof(array[0]), exch_int);


cleanup:
	exit(ret);
}
