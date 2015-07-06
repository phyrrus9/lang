#include "AST_bool.h"
#include "../AST/AST_structures.h"
#include "AST_parse.h"
#include <stdlib.h>
#include <string.h>

#define ExxTrue(a) \
parseData = a;\
return true;
bool E01() {
	enum parseType t;
	struct E01_st *ret;
	if ((t = T()) == tERR)
		return false;
	ret = malloc(sizeof(struct E01_st));
	ret->t = t;
	ret->match = parseData;
	ExxTrue(ret);
}
bool E02() {
	struct E02_st *ret = malloc(sizeof(struct E02_st));
	ret->match[0] = ret->match[1] = NULL;
	if ((ret->t[0] = T()) == tERR)
		goto err;
	ret->match[0] = parseData;
	if (!whiteSpace1Plus()) goto err;
	if (*next++ != '+') goto err;
	if (!whiteSpace1Plus()) goto err;
	if ((ret->t[1] = E()) == tERR)
		goto err;
	ret->match[1] = parseData;
	ExxTrue(ret);
err:
	if (ret->match[0] != NULL)
		free(ret->match[0]);
	if (ret->match[1] != NULL)
		free(ret->match[1]);
	free(ret);
	return false;
}
bool E03() {
	struct E03_st *ret = malloc(sizeof(struct E03_st));
	ret->match[0] = ret->match[1] = NULL;
	if ((ret->t[0] = T()) == tERR)
		goto err;
	ret->match[0] = parseData;
	if (!whiteSpace1Plus()) goto err;
	if (*next++ != '-') goto err;
	if (!whiteSpace1Plus()) goto err;
	if ((ret->t[1] = E()) == tERR)
		goto err;
	ret->match[1] = parseData;
	ExxTrue(ret);
err:
	if (ret->match[0] != NULL)
		free(ret->match[0]);
	if (ret->match[1] != NULL)
		free(ret->match[1]);
	free(ret);
	return false;
}
#undef ExxTrue
