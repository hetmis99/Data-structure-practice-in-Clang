#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL) return TRUE;
	return FALSE;
}

void SPush(Stack* pstack, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = pstack->head;
	pstack->head = newnode; 
}

//Pop; return data while also executing deletion on linked list
Data SPop(Stack* pstack) { 
	if (SIsEmpty(pstack)) exit(-1);
	Data rdata;
	Node* newnode;
	newnode = pstack->head;
	rdata = newnode->data;

	pstack->head = pstack->head->next;
	free(newnode);
	return rdata;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) exit(-1);
	return pstack->head->data;
}