#include <stdlib.h>
#include "AST_parse.h"
#include "AST_bool.h"

int main(int argc, char ** argv)
{
	int i;
	AST = malloc(sizeof(struct AST_block));
	AST->head = AST->tail = NULL;
	AST->num = 0;
	for (i = 1; i < argc; i++)
		parseFile(argv[i], AST);
}
