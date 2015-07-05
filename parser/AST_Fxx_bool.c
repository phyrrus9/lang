#include "AST_bool.h"
#include "../AST/AST_structures.h"
#include "AST_parse.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FxxTrue(a)\
parseData = a;\
return true;
bool F01() {
	struct F01_st *ret = malloc(sizeof(struct F01_st));
	char *buf;
	whiteSpaceAny();
	if (sscanf(next, "%d", &ret->value) < 1)
		goto err;
	buf = malloc(64);
	sprintf(buf, "%d", ret->value);
	next += strlen(buf);
	free(buf);
	FxxTrue(ret);
err:
	free(ret);
	return false;
}
bool F02() {
	struct F02_st *ret = malloc(sizeof(struct F02_st));
	ret->name = malloc(64);
	whiteSpaceAny();
	if (sscanf(next, "%[A-Za-z0-9_]", ret->name) < 1)
		goto err;
	if (isdigit(*ret->name))
		goto err;
	next += strlen(ret->name);
	FxxTrue(ret);
err:
	free(ret->name);
	free(ret);
	return false;
}
#undef FxxTrue
