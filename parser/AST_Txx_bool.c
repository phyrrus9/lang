#include "AST_bool.h"
#include "../AST/AST_structures.h"
#include "AST_parse.h"
#include <stdlib.h>
#include <string.h>

#define TxxTrue(a) \
	parseData = a;\
	return true;
bool T01() {
	enum parseType t;
	struct T01_st *ret;
	if ((t = F()) == tERR)
		return false;
	ret = malloc(sizeof(struct T01_st));
	ret->t = t;
	ret->match = parseData;
	TxxTrue(ret);
}
bool T02() {
	struct T02_st *ret = malloc(sizeof(struct T02_st));
	ret->match[0] = ret->match[1] = NULL;
	if ((ret->t[0] = F()) == tERR)
		goto err;
	ret->match[0] = parseData;
	if (!whiteSpace1Plus()) goto err;
	if (*next++ != '*') goto err;
	if (!whiteSpace1Plus()) goto err;
	if ((ret->t[1] = E()) == tERR)
		goto err;
	ret->match[1] = parseData;
	TxxTrue(ret);
err:
	if (ret->match[0] != NULL)
		free(ret->match[0]);
	if (ret->match[1] != NULL)
		free(ret->match[1]);
	free(ret);
	return false;
}
bool T03() {
	struct T03_st *ret = malloc(sizeof(struct T03_st));
	ret->match[0] = ret->match[1] = NULL;
	if ((ret->t[0] = F()) == tERR)
		goto err;
	ret->match[0] = parseData;
	if (!whiteSpace1Plus()) goto err;
	if (*next++ != '/') goto err;
	if (!whiteSpace1Plus()) goto err;
	if ((ret->t[1] = E()) == tERR)
		goto err;
	ret->match[1] = parseData;
	TxxTrue(ret);
err:
	if (ret->match[0] != NULL)
		free(ret->match[0]);
	if (ret->match[1] != NULL)
		free(ret->match[1]);
	free(ret);
	return false;
}
bool T04() {
	struct T04_st *ret = malloc(sizeof(struct T04_st));
	whiteSpaceAny();
	if (*next++ != '(') goto err;
	if ((ret->t = E()) == tERR)
		goto err;
	ret->match = parseData;
	whiteSpaceAny();
	if (*next++ != ')') goto err;
	TxxTrue(ret);
err:
	free(ret);
	return false;
}
#undef TxxTrue
