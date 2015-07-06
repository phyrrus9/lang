#include "DB_structures.h"
#include "../../AST/AST_structures.h"

#include <stdbool.h>

/* variable prototypes - DB_variable.c */
struct variable_list_st *allocVariableDB();
bool defineVariable(struct variable_list_st **db, char *name);
bool unDefineVariable(struct variable_list_st **db, char *name);
bool setVariable(struct variable_list_st **db, char *name, int value);
int getVariable(struct variable_list_st **db, char *name);
void deAllocVariableDB(struct variable_list_st **db);

/* stack prototypes - DB_stack.c */
stack_ptr_t allocStack();
bool stackPush(stack_ptr_t *sp, int value);
int stackPop(stack_ptr_t *sp);
void deAllocStack(stack_ptr_t *sp);

/* proc prototypes - DB_proc.c */
struct procedure_list_st *allocProcDB();
bool defineProc(struct procedure_list_st **db, char *name, struct AST_block *blk);
struct AST_block *getProc(struct procedure_list_st **db, char *name); //only returns if code exists
void deAllocProcDB(struct procedure_list_st **db);
