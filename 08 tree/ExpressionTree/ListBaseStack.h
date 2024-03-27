#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

typedef BTreeNode* Data;

typedef struct _Node {
	Data data;
	struct _Node* next;
}Node;

typedef struct _listStack_ {
	Node *head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);
#endif
