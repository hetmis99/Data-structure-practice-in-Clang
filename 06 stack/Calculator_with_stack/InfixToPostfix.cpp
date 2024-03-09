#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op) {
	switch (op) {
	case '(': return 1;
	case '+':
	case '-': return 3;
	case '/':
	case '*': return 5;
	}
	return -1;
}

int CompareOp(char op1, char op2) {
	int op1prec = GetOpPrec(op1);
	int op2prec = GetOpPrec(op2);
	if (op1prec > op2prec) return 1;
	else if (op1prec < op2prec) return -1;
	else return 0;
}

void ConvToRPNEXP(char exp[]) {
	Stack stack;
	int explen = strlen(exp);
	char* ConvExp = (char*)malloc(explen + 1);

	int i, idx = 0;
	char tok, popOp;
	memset(ConvExp, 0, sizeof(char)*(explen+1));
	StackInit(&stack);

	for (i = 0; i < explen; i++) {
		tok = exp[i];
		if (isdigit(tok))
			ConvExp[idx++] = tok;
		else {
			switch (tok) {
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(') break;
					ConvExp[idx++] = popOp;
				}
				break;
			default:
				while (!SIsEmpty(&stack) && CompareOp(SPeek(&stack),tok) >= 0) {
					ConvExp[idx++] = SPop(&stack);
				}

				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))
		ConvExp[idx++] = SPop(&stack);

	strcpy(exp, ConvExp);
	free(ConvExp);
};