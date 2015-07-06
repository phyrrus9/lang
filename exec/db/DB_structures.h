#ifndef VARS_STRUCTURES_H
#define VARS_STRUCTURES_H

#include <stdbool.h>
#include "../../AST/AST_structures.h"

/* variable structures */
struct variable_node_st {
	char name[64];
	//char scope[64]; //if var defined in proc main, it would be main_<name>
	//bool global;
	int value;
	struct variable_node_st *next;
};
struct variable_list_st {
	struct variable_node_st *head,
				*tail;
	int num;
};
/* stack structure */
struct stack_node_st {
	int value;
	struct stack_node_st *next;
};
typedef struct stack_node_st* stack_ptr_t;
/* proc structures */
struct procedure_node_st {
	/*
	  node is created one of two ways:
	  defproc:
		create node, but leave code=NULL
	  proc:
		if node exists:
			if code==NULL: set code to the block
			else: error for re-assignment
		else:
			create node, set code to block
	*/
	char name[64];
	struct AST_block *code;
	struct procedure_node_st *next;
};
struct procedure_list_st {
	struct procedure_node_st *head,
				 *tail;
	int num;
};

#endif
