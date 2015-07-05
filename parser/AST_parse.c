#include "AST_parse.h"
#include "AST_bool.h"
#include "../AST/AST_structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>

char *next; //ptr to input stream
void *parseData; //ptr to struct type returned
struct AST_block *AST;

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
	ret = parseBlock((struct AST_block *)AST_in);
	free(save);
	return ret;
}
bool parseBlock(struct AST_block *AST_in)
{
	enum parseType t;
	struct AST_block_node *ins;
	do {
		if ((t = S()) == tERR)
			return false;
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
