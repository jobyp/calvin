#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lib.h"


typedef struct stack_t {
	size_t n;
	size_t sz;
	char **array;
} stack_t;


static bool resize(stack_t *stack, size_t capacity)
{
	char **array = NULL;

	if (capacity == 0)
	{
		log("resize() called with capicity = 0");
		return false;
	}

	if ((array = realloc(stack->array, capacity * sizeof(char *))) != NULL)
	{
		stack->array = array;
		stack->sz = capacity;
		return true;
	}
	else
		return false;
}

static bool is_stack_empty(stack_t *stack)
{
	return (stack->n == 0);
}

static char *pop(stack_t *stack)
{
	char *str = NULL;

	if (is_stack_empty(stack))
		return NULL;

	if (stack->n * 4 <= stack->sz)
		resize(stack, stack->sz / 2);

	stack->n -= 1;
	str = stack->array[stack->n];
	stack->array[stack->n] = NULL;

	return str;
}

static bool push(stack_t *stack, char *str)
{
	char *_str = NULL;

	if ((_str = strdup(str)) == NULL)
	{
		logperror("stdup()");
		return false;
	}

	if (stack->n == stack->sz)
	{
		if (stack->sz == 0)
			resize(stack, 1);
		else
			resize(stack, stack->sz * 2);
	}

	stack->array[stack->n] = _str;
	stack->n++;
	return true;
}

static void pop_stack(stack_t *stack)
{
	for(char *str = pop(stack); str != NULL; str = pop(stack))
	{
		printf("%s ", str);
		free(str);
		str = NULL;
	}

	printf("\n");
}

int main()
{
	int ret	= EXIT_SUCCESS;
	char *line = NULL;
	size_t n = 0;
	char *saveptr = NULL; /* for strtok_r */
	stack_t stack = { .n = 0, .sz = 0, .array = NULL, };
	char *str = NULL;

	while(getline(&line, &n, stdin) != -1)
	{
		for(char *token = strtok_r(line, " \t\n", &saveptr);
		    token != NULL;
		    token = strtok_r(NULL, " \t\n", &saveptr))
		{
			if (strncmp("-", token, 1) == 0)
			{
				if ((str = pop(&stack)) != NULL)
				{
					free(str);
					str = NULL;
				}
				else if (!is_stack_empty(&stack))
				{
					log("pop() failed -- is stack empty?");
					ret = EXIT_FAILURE;
					goto cleanup;
				}
			}
			else
			{
				if (!push(&stack, token))
				{
					log("push() failed");
					ret = EXIT_FAILURE;
					pop_stack(&stack);
					goto cleanup;
				}
			}
		}

	}

	pop_stack(&stack);

cleanup:
	if (stack.array != NULL)
	{
		free(stack.array);
		stack.n = 0;
		stack.sz = 0;
		stack.array = NULL;
	}

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}

	exit(ret);
}
