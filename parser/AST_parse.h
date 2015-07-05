#include <stdbool.h>
#include "../AST/AST_structures.h"

bool parseFile(char *, struct AST_block *);
bool parseBlock(struct AST_block *);
bool whiteSpace1();
void whiteSpaceAny();
bool whiteSpace1Plus();
