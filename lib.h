#ifndef __LIB_H__
#define __LIB_H__

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define log(msg)							\
	do {								\
		fprintf(stderr, "[%s:%s:%d] " msg "\n",			\
			__FILE__, __func__, __LINE__);			\
	} while(false)

#define debug(msg, ...)							\
	do {								\
		fprintf(stderr, "[%s:%s:%d] " msg "\n",			\
			__FILE__, __func__, __LINE__,  __VA_ARGS__);	\
	} while(false)

#define logperror(msg)							\
	do {								\
		char error_msg[120];					\
		char *_err;						\
		_err = strerror_r(errno, error_msg, sizeof(error_msg));	\
		debug("%s %s", msg, _err);				\
	} while(false)

typedef int       cmp_t(void *a,   size_t i,   size_t j);
typedef void     exch_t(void *a,   size_t i,   size_t j);
typedef void     copy_t(void *dst, void  *src, size_t i, size_t j);
typedef void copy_elt_t(void *a, size_t i, void *elt); /* should be exch */
typedef bool     sort_t(void *array, size_t len, size_t item_sz,
			cmp_t cmp, exch_t exch, copy_t copy);

typedef unsigned int uint;


bool initialize_random(void);
void shuffle(void *array, size_t len, exch_t exch);

#endif /* __LIB_H__ */
