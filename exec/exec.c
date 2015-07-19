#include "../AST/AST_structures.h"
#include "DB/DB_structures.h"
#include "DB/DB_prototypes.h"
#include <stdlib.h>

#define CEX(a, b) (struct a *)(b)

struct AST_block_node *ip = NULL; //instruction ptr

bool exec(struct AST_block *ptr) {
	ip = ptr->head;
	return processCode();
}
bool processCode() {
	enum parseType t;
	void *obj;
	while (ip != NULL) {
		//copy the struct stuff
		t = ip->t;
		obj = ip->match;
		//increment the up
		ip = ip->next;
		//processing section
		switch (t) {
			case tNOCODE: continue;
			case tERR: return false;
			case tS04:
				XS04(CEX(S04_st, obj));
				break;
			case tS05:
				XS05(CEX(S04_st, obj));
				break;
			case tS06:
				XS06(CEX(S04_st, obj));
				break;
			case tS07:
				XS07(CEX(S04_st, obj));
				break;
			case tS08:
				XS08(CEX(S04_st, obj));
				break;
			case tS09:
				XS09(CEX(S04_st, obj));
				break;
			case tS10:
				XS10(CEX(S04_st, obj));
				break;
			case tS11:
				XS11(CEX(S04_st, obj));
				break;
			case tS12:
				XS12(CEX(S04_st, obj));
				break;
			case tS13:
				XS13(CEX(S04_st, obj));
				break;
			case tS14:
				XS14(CEX(S04_st, obj));
				break;
			case tS15:
				XS15(CEX(S04_st, obj));
				break;
			case tS16:
				XS16(CEX(S04_st, obj));
				break;
			case tS17:
				XS17(CEX(S04_st, obj));
				break;
			case tS18:
				XS18(CEX(S04_st, obj));
				break;
			case tS20:
				XS20(CEX(S04_st, obj));
				break;
			default: continue;
		}
	}
}

void XS04(struct S04_st *d) {
	//return expression;
	XS08(d->assign);
	XS03(); //return
}
void XS05(struct S05_st *d) {
	//expression;
	//ignored because no result is stored
}
void XS06(struct S06_st *d) {
	//def var
	if (!defineVariable(&variableList, d->name))
		fprintf(stderr, "%s is already defined!\n", d->name);
}
void XS07(struct S07_st *d) {
	//undef var
	if (!unDefineVariable(&variableList, d->name))
		fprintf(stderr, "%s is not defined!\n", d->name);
}
void XS08(struct S08_st *d) {
	//var = expression;
	int eval;
	int (*fnc)(void *) = NULL;
	defineVariable(&variableList, d->name); //define if not exists
	switch (d->t) {
		case tE01:
			fnc = &XE01;
			break;
		case tE02:
			fnc = &XE02;
			break;
		case tE03:
			fnc = &XE03;
			break;
		default:
			fprintf(stderr, "Unknown expression\n");
			abort();
	}
	eval = *fnc(d->match);
	setVariable(&variableList, d->name, eval);
}
void XS09(struct S09_st *d) {
	//proc fnc = [blk];
	if (getProc(&procList, d->name) != NULL)
		fprintf(stderr, "%s : proc already coded!\n", d->name);
	else
		defineProc(&procList, d->name, d->statements);
}
void XS10(struct S10_st *d) {
	//procdef
	if (getProc(&procList, d->name) == NULL)
		defineProc(&procList, d->name, NULL);
}
//XS12 next
