#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

bool initialize_random(void)
{
	uint seed = 1;

	if (getentropy(&seed, sizeof(seed)) == -1)
	{
		logperror("getentropy()");
		return false;
	}

	srandom(seed);
	return true;
}

void shuffle(void *array, size_t len, exch_t exch)
{
	size_t i;
	size_t j;

	for(i = 1; i < len; i++)
	{
		j = (size_t) (random() % (i + 1));
		exch(array, i, j);
	}
}
