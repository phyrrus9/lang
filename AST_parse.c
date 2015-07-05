bool parseFile(char *fname, struct block *AST) {
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
	ret = parseBlock(AST);
	free(save);
	return ret;
}
bool parseBlock(struct block *AST) {
	enum parseType t;
	struct block_node *ins;
	do {
		if ((t = S()) == tERR)
			return false;
		if (t == tNOCODE) continue;
		ins = malloc(sizeof(struct block_node));
		ins->t = t;
		ins->match = parseData;
		ins->next = NULL;
		if (AST->head != NULL) {
			AST->tail->next = ins;
			AST->tail = ins;
		}
		else
			AST->head = AST->tail = ins;
		++AST->num;
	} while (*next);
	return true;
}
bool whiteSpace1() {
	char c = *next++;
	return (c == ' '  || c == '\t') ||
	       (c == '\r' || c == '\n');
}
void whiteSpaceAny() {
	while (whiteSpace1());
}