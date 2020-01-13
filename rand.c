#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

typedef unsigned int uint;

int main()
{
	uint seed;
	int ret = EXIT_SUCCESS;

	if (getentropy(&seed, sizeof(seed)) == -1)
	{
		logperror("getentropy()");
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	printf("seed = %u\n", seed);

	srandom(seed);

	for(size_t i = 0; i < 10; i++)
		printf("random() = %d\n", (uint)(random()%(i + 1)));
	
cleanup:
	exit(ret);
}
