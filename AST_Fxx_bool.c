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
bool F01() {
	struct F01_st *ret = malloc(sizeof(struct F01_st));
	ret->name = malloc(64);
	whiteSpaceAny();
	if (sscanf(next, "%s", ret->name) < 1)
		goto err;
	next += strlen(ret->value);
	FxxTrue(ret);
err:
	free(ret->name);
	free(ret);
	return false;
}
#undef FxxTrue