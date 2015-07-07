#include "../../AST/AST_structures.h"
#include "DB_structures.h"
#include "DB_prototypes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct procedure_node_st *proc_exists(struct procedure_list_st *db, char *name) {
	struct procedure_node_st *tmp;
	if (strlen(name) > 63)
		DB_error("[ERROR]", "Procedure name %s is too long!\n", true, name);
	for (tmp = db->head; tmp != NULL; tmp = tmp->next)
		if (!strcmp(name, tmp->name))
			return tmp;
	return NULL;
}
struct procedure_list_st *allocProcDB() {
	struct procedure_list_st *ret = malloc(sizeof(struct procedure_list_st));
	ret->head = ret->tail = NULL;
	ret->num = 0;
	return ret;
}
bool defineProc(struct procedure_list_st **db, char *name, struct AST_block *blk) {
	struct procedure_node_st *tmp;
	struct procedure_node_st *ins = malloc(sizeof(struct procedure_node_st));
	tmp = proc_exists(*db, name);
	strcpy(ins->name, name);
	ins->code = blk;
	ins->next = NULL;
	if (blk == NULL) { //define only
		if (tmp != NULL) {
			return false;
		}
	}
	else {
		if (tmp == NULL)
			defineProc(db, name, NULL);
		if (tmp->code != NULL)
			DB_error("[ERROR]", "Procedure %s already exists!\n", true, name);
	}
	(*db)->tail->next = ins;
	(*db)->tail = ins;
	++((*db)->num);
	return true;
}
struct AST_block *getProc(struct procedure_list_st **db, char *name) { //only returns if code exists
	struct procedure_node_st *tmp = proc_exists(*db, name);
	if (tmp->code == NULL)
		DB_error("[ERROR]", "Cannot find code for %s\n", true, name);
	return tmp->code;
}
void deAllocProcNode(struct procedure_node_st *n) {
	if (n == NULL) return;
	deAllocProcNode(n->next);
	free(n);
}
void deAllocProcDB(struct procedure_list_st **db) {
	deAllocProcNode((*db)->head);
	(*db)->head = (*db)->tail = NULL;
	(*db)->num = 0;
	free(*db);
	*db = NULL;
}
