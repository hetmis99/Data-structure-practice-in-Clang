#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {
	Stack stack;
	int explen = strlen(exp);
	int i;
	char tok, pop1, pop2;

	StackInit(&stack);

	for (i = 0; i < explen; i++) {
		tok = exp[i];
		if (isdigit(tok))
			SPush(&stack, tok - '0'); // converts tok to integer and push it to the stack
		else {
			pop2 = SPop(&stack); // second operand
			pop1 = SPop(&stack); // first operand
			switch (tok) {
			case '+':
				SPush(&stack, pop1 + pop2);
				break;
			case'-':
				SPush(&stack, pop1 - pop2);
				break;
			case'*':
				SPush(&stack, pop1 * pop2);
				break;
			case'/':
				SPush(&stack, pop1 / pop2);
				break;
			}
		}
	}

	return SPop(&stack);
};