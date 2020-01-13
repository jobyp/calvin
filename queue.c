#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "lib.h"


typedef struct qnode {
	void *data;
	struct qnode *prev;
	struct qnode *next;
} qnode_t;

typedef struct queue_t {
	qnode_t *head;
	qnode_t *tail;
} queue_t;


static bool is_queue_empty(queue_t *queue)
{
	bool empty = (queue->tail == NULL);

	if (empty)
		assert (queue->head == NULL);

	return empty;
}

static bool enqueue(queue_t *queue, void *data)
{
	qnode_t *node = NULL;
	qnode_t *tail = NULL;

	if ((node = malloc(sizeof(qnode_t))) == NULL)
	{
		logperror("malloc()");
		return false;
	}

	node->data = data;
	node->prev = NULL;
	node->next = NULL;

	/* We add the node at the tail end */

	if (is_queue_empty(queue))
	{
		queue->tail = node;
		queue->head = node;
		return true;
	}
	else
	{
		tail = queue->tail;
		node->prev = tail;;
		tail->next = node;
		queue->tail = node;
		return true;
	}
}

static void* dequeue(queue_t *queue)
{
	qnode_t *node = NULL;
	void *data = NULL;

	if (is_queue_empty(queue))
		return NULL;

	node = queue->head;
	data = node->data;

	/* Queue might have only one node */
	if (queue->head == queue->tail)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else /* Queue has more than 1 node */
	{
		queue->head = node->next;
		if (queue->head != NULL)
			queue->head->prev = NULL;
	}

	free(node);
	node = NULL;

	return data;
}

static void free_queue(queue_t *queue)
{
	while(!is_queue_empty(queue))
		dequeue(queue);
}

static void print_queue_fifo(queue_t *queue)
{
	char *str = NULL;

	for(qnode_t *node = queue->head; node != NULL; node = node->next)
	{
		str = (char *)node->data;
		printf("%s ", str);
	}
	printf("\n");
}

static void print_queue_lifo(queue_t *queue)
{
	char *str = NULL;

	for(qnode_t *node = queue->tail; node != NULL; node = node->prev)
	{
		str = (char *)node->data;
		printf("%s ", str);
	}
	printf("\n");
}

int main()
{
	int ret = EXIT_SUCCESS;
	char *line = NULL;
	size_t n = 0;
	char *str = NULL;
	char *saveptr = NULL;
	char *delimit = " \t\n";
	queue_t queue = {.head = NULL, .tail = NULL};

	while ((getline(&line, &n, stdin)) != -1)
	{
		for(char *token = strtok_r(line, delimit, &saveptr);
		    token != NULL;
		    token = strtok_r(NULL, delimit, &saveptr))
		{
			if (strncmp("-", token, 1) == 0)
			{
				if ((str = (char *)dequeue(&queue)) != NULL)
				{
					free(str);
					str = NULL;
				}
			}
			else
			{
				if ((str = strdup(token)) == NULL)
				{
					logperror("strdup()");
					goto cleanup;
				}

				if (!enqueue(&queue, str))
				{
					log("enqueue() failed");
					goto cleanup;
				}
			}
		}
	}

	print_queue_fifo(&queue);
	print_queue_lifo(&queue);

cleanup:

	free_queue(&queue);

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}

	exit(ret);
}
