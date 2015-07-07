#include "DB_prototypes.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void DB_error(char *msg, char *fmt, bool die, ...) {
	char *buf = malloc(strlen(msg) + strlen(fmt) + 6);
	sprintf(buf, "%s %s", msg, fmt);
	va_list args;
	va_start(args, die);
	vfprintf(stderr, buf, args);
	va_end(args);
	free(buf);
	if (die)
		exit(-1);
};
