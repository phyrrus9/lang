#include "AST_bool.h"
#include "../AST/AST_structures.h"
#include "AST_parse.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SxxTrue(a) \
	parseData = a;\
	return true;
bool S01() {
	char *ret = malloc(512);
	if (sscanf(next, "REM %[^\n]\n", ret) < 1)
		return false;
	next +=   strlen("REM ")
		+ strlen(ret);
	free(ret);
	SxxTrue(NULL);
}
bool S02() {
	if (*next != ';')
		return false;
	++next;
	SxxTrue(NULL);
}
bool S03() {
	if (strncmp("return;", next, strlen("return;")))
		return false;
	next += strlen("return;");
	SxxTrue(NULL);
}
bool S04() {
	struct S04_st *ret;
	enum parseType assign = tERR;
	if (strncmp("return ", next, strlen("return ")))
		return false;
	next += strlen("return ");
	if ((assign = E()) == tERR)
		return false;
	if (*next != ';')
		return false;
	++next;
	ret = malloc(sizeof(struct S04_st));
	ret->assign = malloc(sizeof(struct S08_st));
	ret->assign->t = assign;
	ret->assign->match = parseData;
	ret->assign->name = (char *)"r";
	SxxTrue(ret);
}
bool S05() {
	struct S05_st *ret;
	enum parseType t;
	if ((t = E()) == tERR)
		return false;
	if (*next != ';')
		return false;
	++next;
	ret = malloc(sizeof(struct S05_st));
	ret->t = t;
	ret->match = parseData;
	SxxTrue(ret);
}
bool S06() {
	struct S06_st *ret = malloc(sizeof(struct S06_st));
	ret->name = malloc(64);
	if (sscanf(next, "def %[^;];", ret->name) < 1) {
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("def ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S07() {
	struct S07_st *ret = malloc(sizeof(struct S07_st));
	ret->name = malloc(64);
	if (sscanf(next, "undef %[^;];", ret->name) < 1) {
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("undef ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S08() {
	struct S08_st *ret = malloc(sizeof(struct S08_st));
	ret->name = malloc(64);
	if (sscanf(next, "%s = ", ret->name) < 1)
		goto err;
	next += strlen(ret->name) + strlen(" = ");
	if ((ret->t = E()) == tERR)
		goto err;
	ret->match = parseData;
	whiteSpaceAny();
	if (*next++ != ';')
		goto err;
	SxxTrue(ret);
err:
	free(ret->name);
	free(ret);
	return false;
}
bool S09() {
	struct S09_st *ret = malloc(sizeof(struct S09_st));
	ret->name = malloc(64);
	if (sscanf(next, "proc %[A-Za-z0-9_] =", ret->name) < 1)
		goto err;
	if (isdigit(*ret->name))
		goto err;
	whiteSpaceAny();
	next += strlen("proc ") + strlen(ret->name) +
		strlen(" =");
	ret->statements = malloc(sizeof(struct AST_block));
	ret->statements->head = ret->statements->tail = NULL;
	ret->statements->num = 0;
	if (!parseBlock(ret->statements))
		goto err;
	whiteSpaceAny();
	if (*next++ != ';')
		goto err;
	SxxTrue(ret);
err:
	free(ret->name);
	free(ret);
	return false;
}
bool S10() {
	struct S10_st *ret = malloc(sizeof(struct S10_st));
	ret->name = malloc(64);
	if (sscanf(next, "procdef %[^;];", ret->name) < 1) {
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("procdef ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S11() {
	struct S07_st *ret = malloc(sizeof(struct S07_st));
	ret->name = malloc(64);
	if (sscanf(next, "def %[^;];", ret->name) < 1) {
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("undef ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S12() {
	struct S12_st *ret = malloc(sizeof(struct S12_st));
	if (strncmp("print ", next, strlen("print ")))
		goto err;
	next += strlen("print ");
	if ((ret->t = E()) == tERR)
		goto err;
	ret->match = parseData;
	SxxTrue(ret);
err:
	free(ret);
	return false;
}
bool S13() {
	struct S13_st *ret = malloc(sizeof(struct S13_st));
	if (strncmp("printc ", next, strlen("printc ")))
		goto err;
	next += strlen("printc ");
	if ((ret->t = E()) == tERR)
		goto err;
	ret->match = parseData;
	SxxTrue(ret);
err:
	free(ret);
	return false;
}
bool S14() {
	struct S14_st *ret = malloc(sizeof(struct S14_st));
	ret->name = malloc(64);
	if (sscanf(next, "read %[^;];", ret->name) < 1)
	{
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("read ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S15() {
	struct S15_st *ret = malloc(sizeof(struct S15_st));
	ret->name = malloc(64);
	if (sscanf(next, "readc %[^;];", ret->name) < 1)
	{
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("readc ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S16() {
	struct S16_st *ret = malloc(sizeof(struct S16_st));
	ret->name = malloc(64);
	if (sscanf(next, "call %[^;];", ret->name) < 1)
	{
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("call ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S17() {
	struct S17_st *ret = malloc(sizeof(struct S17_st));
	if (strncmp("push ", next, strlen("push ")))
		goto err;
	next += strlen("push ");
	if ((ret->t = E()) == tERR)
		goto err;
	if (*next++ != ';')
		goto err;
	ret->match = parseData;
	SxxTrue(ret);
err:
	free(ret);
	return false;
}
bool S18() {
	struct S18_st *ret = malloc(sizeof(struct S18_st));
	ret->name = malloc(64);
	if (sscanf(next, "pop %[^;];", ret->name) < 1)
	{
		free(ret->name);
		free(ret);
		return false;
	}
	next += strlen("pop ") + strlen(ret->name) + 1;
	SxxTrue(ret);
}
bool S19() {
	char *save, *fname = malloc(128);
	if (strncmp("parse('", next, strlen("parse('")))
		goto err;
	next += strlen("parse('");
	if (sscanf(next, "%[^']');", fname) < 1)
		goto err;
	next += strlen(fname) + strlen("');");
	save = next;
	if (!parseFile(fname, AST))
		fprintf(stderr, "Error parsing %s\n", fname);
	next = save;
	free(fname);
	SxxTrue(NULL);
err:
	free(fname);
	return false;
}
bool S20() {
	struct S20_st *ret = malloc(sizeof(struct S20_st));
	ret->ifTrue = malloc(64);
	ret->ifFalse = malloc(64);
	if (strncmp("if (", next, strlen("if (")))
		goto err;
	next += strlen("if (");
	if ((ret->t = E()) == tERR)
		goto err;
	ret->match = parseData;
	if (strncmp(") -> ", next, strlen(") -> ")))
		goto err;
	next += strlen(") -> ");
	if (sscanf(next, "%s", ret->ifTrue) < 1)
		goto err;
	next += strlen(ret->ifTrue);
	if (strncmp(" : ", next, strlen(" : ")))
		goto err;
	next += strlen(" : ");
	if (sscanf(next, "%[^;]", ret->ifFalse) < 1)
		goto err;
	next += strlen(ret->ifFalse);
	if (*next++ != ';') goto err;
	SxxTrue(ret);
err:
	free(ret->ifTrue);
	free(ret->ifFalse);
	free(ret);
	return false;
}
bool S21() {
	if (strncmp("/*", next, strlen("/*")))
		goto err;
	next += strlen("/*");
	while (strncmp("*/", next++, strlen("*/")))
		if (*next == 0)
			goto err;
	return true;
err:
	return false;
}
#undef SxxTrue
