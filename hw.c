#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lib.h"

#define DICT "/usr/share/dict/words"


/* static bool match(const char *word) */
/* { */
/* 	const char *_word = word; */
/* /\*start: *\/ */
/* 	if ((_word = strchr(_word, 'a')) != NULL) */
/* 		goto a; */
/* 	else */
/* 		goto fail; */
/* a: */
/* 	if ((_word = strchr(_word, 'e')) != NULL) */
/* 		goto e; */
/* 	else */
/* 		goto fail; */

/* e: */
/* 	if ((_word = strchr(_word, 'i')) != NULL) */
/* 		goto i; */
/* 	else */
/* 		goto fail; */

/* i: */
/* 	if ((_word = strchr(_word, 'o')) != NULL) */
/* 		goto o; */
/* 	else */
/* 		goto fail; */

/* o: */
/* 	if ((_word = strchr(_word, 'u')) != NULL) */
/* 		goto u; */
/* 	else */
/* 		goto fail; */

/* u: */
/* 	return true; */
/* fail: */
/* 	return false; */
/* } */

static bool match_sorted(const char *word)
{
	const char *_word = word;

	if (!word) /* null string ?? */
		return false;
/*start: */
	switch(_word[0]) {
	case 'a' : if (_word[1] == '\0') return true; else _word++; goto a;
	case 'b' : if (_word[1] == '\0') return true; else _word++; goto b;
	case 'c' : if (_word[1] == '\0') return true; else _word++; goto c;
	case 'd' : if (_word[1] == '\0') return true; else _word++; goto d;
	case 'e' : if (_word[1] == '\0') return true; else _word++; goto e;
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

a:
	switch(_word[0]) {
	case 'a' : if (_word[1] == '\0') return true; else _word++; goto a;
	case 'b' : if (_word[1] == '\0') return true; else _word++; goto b;
	case 'c' : if (_word[1] == '\0') return true; else _word++; goto c;
	case 'd' : if (_word[1] == '\0') return true; else _word++; goto d;
	case 'e' : if (_word[1] == '\0') return true; else _word++; goto e;
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

b:
	switch(_word[0]) {
	case 'b' : if (_word[1] == '\0') return true; else _word++; goto b;
	case 'c' : if (_word[1] == '\0') return true; else _word++; goto c;
	case 'd' : if (_word[1] == '\0') return true; else _word++; goto d;
	case 'e' : if (_word[1] == '\0') return true; else _word++; goto e;
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

c:
	switch(_word[0]) {
	case 'c' : if (_word[1] == '\0') return true; else _word++; goto c;
	case 'd' : if (_word[1] == '\0') return true; else _word++; goto d;
	case 'e' : if (_word[1] == '\0') return true; else _word++; goto e;
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

d:
	switch(_word[0]) {
	case 'd' : if (_word[1] == '\0') return true; else _word++; goto d;
	case 'e' : if (_word[1] == '\0') return true; else _word++; goto e;
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

e:
	switch(_word[0]) {
	case 'e' : if (_word[1] == '\0') return true; else _word++; goto e;
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

f:
	switch(_word[0]) {
	case 'f' : if (_word[1] == '\0') return true; else _word++; goto f;
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

g:
	switch(_word[0]) {
	case 'g' : if (_word[1] == '\0') return true; else _word++; goto g;
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

h:
	switch(_word[0]) {
	case 'h' : if (_word[1] == '\0') return true; else _word++; goto h;
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

i:
	switch(_word[0]) {
	case 'i' : if (_word[1] == '\0') return true; else _word++; goto i;
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

j:
	switch(_word[0]) {
	case 'j' : if (_word[1] == '\0') return true; else _word++; goto j;
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

k:
	switch(_word[0]) {
	case 'k' : if (_word[1] == '\0') return true; else _word++; goto k;
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

l:
	switch(_word[0]) {
	case 'l' : if (_word[1] == '\0') return true; else _word++; goto l;
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

m:
	switch(_word[0]) {
	case 'm' : if (_word[1] == '\0') return true; else _word++; goto m;
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

n:
	switch(_word[0]) {
	case 'n' : if (_word[1] == '\0') return true; else _word++; goto n;
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

o:
	switch(_word[0]) {
	case 'o' : if (_word[1] == '\0') return true; else _word++; goto o;
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

p:
	switch(_word[0]) {
	case 'p' : if (_word[1] == '\0') return true; else _word++; goto p;
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

q:
	switch(_word[0]) {
	case 'q' : if (_word[1] == '\0') return true; else _word++; goto q;
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

r:
	switch(_word[0]) {
	case 'r' : if (_word[1] == '\0') return true; else _word++; goto r;
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

s:
	switch(_word[0]) {
	case 's' : if (_word[1] == '\0') return true; else _word++; goto s;
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

t:
	switch(_word[0]) {
	case 't' : if (_word[1] == '\0') return true; else _word++; goto t;
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

u:
	switch(_word[0]) {
	case 'u' : if (_word[1] == '\0') return true; else _word++; goto u;
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}
v:
	switch(_word[0]) {
	case 'v' : if (_word[1] == '\0') return true; else _word++; goto v;
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}
w:
	switch(_word[0]) {
	case 'w' : if (_word[1] == '\0') return true; else _word++; goto w;
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}
x:
	switch(_word[0]) {
	case 'x' : if (_word[1] == '\0') return true; else _word++; goto x;
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}
y:
	switch(_word[0]) {
	case 'y' : if (_word[1] == '\0') return true; else _word++; goto y;
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}
z:
	switch(_word[0]) {
	case 'z' : if (_word[1] == '\0') return true; else _word++; goto z;
	default	 : goto fail;
	}

fail:
	return false;
}

static void print_words()
{
	char *line = NULL;
	size_t n = 0;
	ssize_t ret;

	while ((ret = getline(&line, &n, stdin)) != -1) {

		for(char *p = line; *p != '\0'; p++) {
			if (*p == '\n') {
				*p = '\0';
				break;
			}
		}

		if (match_sorted(line))
			puts(line);
	}

	if (line != NULL)
		free(line);

	return;
}

int main()
{
	print_words();
	exit(EXIT_SUCCESS);
}

