#include "DB_structures.h"
#include "DB_prototypes.h"
#include <stdlib.h>

stack_ptr_t allocStackNode(int v, stack_ptr_t ptr) {
	stack_ptr_t ret = malloc(sizeof(struct stack_node_st));
	if (ret == NULL)
		DB_error("[ERROR]", "Could not allocate stack node\n", true);
	ret->value = v;
	ret->next = ptr;
	return ret;
}
stack_ptr_t allocStack() {
	return NULL;
}
bool stackPush(stack_ptr_t *sp, int value) {
	stack_ptr_t tmp;
	if ((tmp = allocStackNode(value, *sp)) == NULL)
		return false;
	*sp = tmp;
	return true;
}
int stackPop(stack_ptr_t *sp) {
	int ret;
	stack_ptr_t tmp = *sp;
	if (sp == NULL)
		DB_error("[ERROR]", "Stack fault\n", true);
	ret = tmp->value;
	*sp = tmp->next;
	free(tmp);
	return ret;
}
void deAllocStack(stack_ptr_t *sp) {
	if (*sp == NULL) return;
	if ((*sp)->next != NULL)
		deAllocStack(&((*sp)->next));
	free(*sp);
}
