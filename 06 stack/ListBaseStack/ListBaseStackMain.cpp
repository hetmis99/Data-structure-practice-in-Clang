#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ListBaseStack.h"

int main() {
	Stack stack;
	StackInit(&stack);

	for (int i = 1; i <= 5; i++) {
		SPush(&stack, i);
	}

	while (!SIsEmpty(&stack)) {
		printf("%d ", SPop(&stack));
	};
}
