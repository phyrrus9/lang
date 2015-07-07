#include "DB_structures.h"
#include "DB_prototypes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

bool var_exists(struct variable_list_st *db, char *name) {
	struct variable_node_st *tmp;
	if (strlen(name) > 63)
		DB_error("[ERROR]", "variable name %s is too long!\n", true, name);
	for (tmp = db->head; tmp != NULL; tmp = tmp->next)
		if (!strcmp(name, tmp->name)) return true;
	return false;
}
struct variable_node_st *get_var(struct variable_list_st *db, char *name) {
	struct variable_node_st *tmp;
	if (strlen(name) > 63)
		DB_error("[ERROR]", "variable name %s is too long!\n", true, name);
	for (tmp = db->head; tmp != NULL; tmp = tmp->next)
		if (!strcmp(name, tmp->name)) return tmp;
	DB_error("[ERROR]", "Variable %s does not exist!\n", name, true);
	return NULL; //this will never be executed
}
struct variable_list_st *allocVariableDB() {
	struct variable_list_st *ret = malloc(sizeof(struct variable_list_st));
	if (ret == NULL)
		DB_error("[ERROR]", "could not allocate a variable database\n", true);
	ret->head = ret->tail = NULL;
	ret->num = 0;
	return ret;
}
bool defineVariable(struct variable_list_st **db, char *name) {
	struct variable_node_st *ins;
	if (var_exists(*db, name)) {
		DB_error("[WARNING]", "redefining variable %s\n", false, name);
		return true;
	}
	if ((ins = malloc(sizeof(struct variable_node_st))) == NULL)
		DB_error("[ERROR]", "could not allocate space for %s\n", true, name);
	strcpy(ins->name, name);
	if ((*db)->num == INT_MAX)
		DB_error("[ERROR]", "there are too many defined variables. Max: %d\n", INT_MAX);
	if ((*db)->num > 0)
	{
		ins->next = (*db)->head;
		(*db)->head = ins;
	}
	else
		(*db)->head = (*db)->tail = ins;
	++((*db)->num);
	return true;
}
bool unDefineVariable(struct variable_list_st **db, char *name) {
	struct variable_node_st *tmp, *prev, *next;
	if (!var_exists(*db, name))
		DB_error("[ERROR]", "Variable %s was never created or already undefined\n", true, name);
	for (	tmp = (*db)->head, prev = NULL, next = tmp->next;
		tmp != NULL;
		prev = tmp, tmp = tmp->next, next = tmp->next) {
			if (!strcmp(tmp->name, name))
				break;
	}
	if (prev == NULL) { //head
		free(tmp);
		(*db)->head = next;
	} else if (next == NULL) { //tail
		prev->next = NULL;
		free(tmp);
		(*db)->tail = prev;
	}
	else { //somewhere else
		prev->next = next;
		free(tmp);
	}
	--((*db)->num);
	return true;
}
bool setVariable(struct variable_list_st **db, char *name, int value) {
	if (!var_exists(*db, name))
		defineVariable(db, name);
	get_var(*db, name)->value = value;
	return true;
}
int getVariable(struct variable_list_st **db, char *name) {
	if (!var_exists(*db, name))
		DB_error("[ERROR]", "Variable %s does not exist\n", true, name);
	return get_var(*db, name)->value;
}
void deAllocVariableDB(struct variable_list_st **db) {
	struct variable_node_st *tmp, *prev;
	for (tmp = (*db)->head, prev = NULL; tmp != NULL; prev = tmp, tmp = tmp->next)
		if (prev != NULL)
			free(prev);
	if (prev != NULL)
		free(prev);
	free(*db);
	*db = NULL;
}
