#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->topindex = -1;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topindex == -1) return TRUE;
	return FALSE;
}

int SIsFull(Stack* pstack) {
	if (pstack->topindex == STACK_LEN - 1) return TRUE;
	return FALSE;
}

void SPush(Stack* pstack, Data data) {
	if (SIsFull(pstack)) return;
	pstack->stackArr[++(pstack->topindex)] = data;
}

Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack)) return -1;
	Data rdata = pstack->stackArr[pstack->topindex];
	(pstack->topindex)--;
	return rdata;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) return -1;
	Data rdata = pstack->stackArr[pstack->topindex];
	return rdata;
}