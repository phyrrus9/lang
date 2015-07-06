#include "AST_parse.h"
#include "AST_bool.h"
#include "../AST/AST_structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>

char *next; //ptr to input stream
void *parseData; //ptr to struct type returned
struct AST_block *AST;

void parseError()
{
	whiteSpaceAny();
	char *msg = strstr(next, "\n");
	if (msg) {
		*msg = 0;
		fprintf(stderr, "Parse error\n\t%s\n", next);
	} else
		fprintf(stderr, "Parse error <unknown>\n");
}

bool parseFile(char *fname, struct AST_block *AST_in)
{
	char *save;
	struct stat st;
	FILE *f = fopen(fname, "r");
	bool ret = false;
	if (f == NULL) return false;
	stat(fname, &st);
	if ((save = next = malloc(st.st_size)) == NULL)
		return false;
	fread(next, st.st_size, 1, f);
	fclose(f);
	ret = parseInput((struct AST_block *)AST_in);
	free(save);
	return ret;
}
bool parseInput(struct AST_block *AST_in)
{
	char *save;
	enum parseType t;
	struct AST_block_node *ins;
	do {
		save = next;
		whiteSpaceAny(); //trim anything off the beginning
		if (*next == 0) break;
		if ((t = S()) == tERR)
			goto err;
		if (t == tNOCODE) continue;
		ins = malloc(sizeof(struct AST_block_node));
		ins->t = t;
		ins->match = parseData;
		ins->next = NULL;
		if (AST_in->head != NULL) {
			AST_in->tail->next = (struct AST_block_node *)ins;
			AST_in->tail = ins;
		}
		else
			AST_in->head = AST_in->tail = ins;
		++AST_in->num;
	} while (*next);
	return true;
err:
	next = save;
	parseError();
	return false;
}
bool parseBlock(struct AST_block *AST_in)
{
	char *save;
	enum parseType t;
	struct AST_block_node *ins;
	whiteSpaceAny(); //we dont care about empty space before the block
	if (*next++ != '[')
		goto err;
	while (*next != ']')
	{
		whiteSpaceAny(); //trim empty space from the beginning of the statement
		if ((t = S()) == tERR)
			goto err;
		if (t == tNOCODE) { whiteSpaceAny(); continue; }
		ins = malloc(sizeof(struct AST_block_node));
		ins->t = t;
		ins->match = parseData;
		ins->next = NULL;
		if (AST_in->head != NULL) {
			AST_in->tail->next = (struct AST_block_node *)ins;
			AST_in->tail = ins;
		}
		else
			AST_in->head = AST_in->tail = ins;
		++AST_in->num;
		whiteSpaceAny(); //remove any whitespace after the statement
	}
	++next; //trim the ] off
	return true;
err:
	next = save;
	parseError();
	return false;
}
bool whiteSpace1() {
	char c = *next;
	if ((c == ' '  || c == '\t') ||
	    (c == '\r' || c == '\n'))
	{
		++next;
		return true;
	}
	return false;
}
void whiteSpaceAny() {
	while (whiteSpace1());
}
bool whiteSpace1Plus() {
	bool ret = whiteSpace1();
	if (ret)
		whiteSpaceAny();
	return ret;
}
