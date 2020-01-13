#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "lib.h"

typedef unsigned int uint;

#define CMDSZ 16

/*
 * Weighthed Union Find Algorithm
 */

static char* strip(char *line)
{
	size_t len = strlen(line);
	size_t i, j;

	for(i = 0; i < len; i++) {

		if (!isspace(line[i]))
			break;
	}


	for(j = len - 1; j >= i; j--) {

		if (!isspace(line[j]))
			break;
	}

	if (j < (len - 1))
		line[j + 1] = '\0';

	return (line + i);
}

static uint root(uint id[], uint i)
{
	while (id[i] != i) {
		id[i] = id[id[i]]; /* Make child point to the grand parent */
		i = id[i];
	}

	return i;
}

static void unite(uint id[], uint sz[], uint p, uint q)
{
	uint root_p = root(id, p);
	uint root_q = root(id, q);

	/* Check if these are already connected */
	if (root_p == root_q)
		return;

	/* Attach smaller sub-tree to the larger tree */
	if (sz[root_p] < sz[root_q]) {
		id[root_p] = root_q;
		sz[root_q] += sz[root_p];
	} else {
		id[root_q] = root_p;
		sz[root_p] += sz[root_q];
	}
}

static bool connected(uint id[], uint p, uint q)
{
	return (root(id, p) == root(id, q));
}


int main()
{
	size_t n;
	char *line = NULL;
	size_t N = 0;
	uint *id = NULL;
	uint *sz = NULL;
	int ret = EXIT_SUCCESS;
	uint a, b;
	char cmd[CMDSZ];

	/* 1. Get number of elements */
	if (getline(&line, &n, stdin) != -1)
		N = (size_t) atol(line);
	else {
		logperror("getline()");
		goto fail;
	}

	if ((id = malloc(N * sizeof(unsigned int))) == NULL) {
		log("malloc() failed");
		ret = EXIT_FAILURE;
		goto fail;
	}

	if ((sz = malloc(N * sizeof(unsigned int))) == NULL) {
		log("malloc() failed");
		ret = EXIT_FAILURE;
		goto fail;
	}

	for(size_t i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}

	while (getline(&line, &n, stdin) != -1) {

		char *_line = strip(line);

		if (strlen(_line) == 0) /* Check EOF */
			break;

		memset(cmd, '\0', CMDSZ * sizeof(char));

		if (sscanf(_line, "%s (%u, %u)", cmd, &a, &b) != 3) {
			log("sscanf() failed");
			printf("[%s]\n", _line);
			ret = EXIT_FAILURE;
			goto fail;
		}

		if (a >= N || b >= N) {
			printf("invalid inputs [%s]\n", _line);
			continue;
		}

		if (strncmp("connected", cmd, CMDSZ) == 0) {

			if (connected(id, a, b))
				printf("connected(%u, %u) = Yes\n", a, b);
			else
				printf("connected(%u, %u) = No\n", a, b);

		} else if (strncmp("union", cmd, CMDSZ) == 0)
			unite(id, sz, a, b);
		else {
			printf("invalid inputs [%s]\n", _line);
			continue;
		}
	}

fail:
	if (sz != NULL) {
		free(sz);
		sz = NULL;
	}

	if (id != NULL) {
		free(id);
		id = NULL;
	}

	if (line) {
		free(line);
		line = NULL;
	}

	exit(ret);
}
