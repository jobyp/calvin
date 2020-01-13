#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lib.h"

typedef struct stack{
	char *str;
	struct stack *next;
} stack_t;

static bool push(stack_t **head, char *str)
{
	stack_t *node;

	if ((node = malloc(sizeof(stack_t))) == NULL) {
		logperror("malloc()");
		return false;
	}

	if ((node->str = strdup(str)) == NULL) {
		logperror("strdup()");
		free(node);
		return false;
	}

	node->next = *head;
	*head = node;
	return true;
}

static char *pop(stack_t **head)
{
	char *str;
	stack_t *node;

	if (*head == NULL)
		return NULL;

	/* update head */
	node = *head;
	*head = node->next;

	/* free node */
	str = node->str;
	free(node);
	node = NULL;

	return str;
}


int main()
{
	stack_t *head = NULL;
	char *line = NULL;
	size_t n = 0;
	int ret = EXIT_SUCCESS;
	char *saveptr = NULL;
	char *str = NULL;

	if (getline(&line, &n, stdin) == -1) {
		logperror("getline()");
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	for(char *token = strtok_r(line, " \n", &saveptr); token != NULL;
	    token = strtok_r(NULL, " \n", &saveptr))
	{
		if (strncmp("-", token, 1) == 0)
		{
			if ((str = pop(&head)) != NULL)
			{
				free(str);
				str = NULL;
			}
		}
		else
		{
			if (!push(&head, token))
			{
				ret = EXIT_FAILURE;
				break;
			}
		}
	}

	/* pop the stack and free the strings */
	while ((str = pop(&head)) != NULL) {
		printf("%s ", str);
		free(str);
		str = NULL;
	}
	printf("\n");

cleanup:

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}

	return ret;
}
