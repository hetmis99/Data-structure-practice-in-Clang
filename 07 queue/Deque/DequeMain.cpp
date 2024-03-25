#include <stdio.h>
#include "Deque.h"

int main() {
	Deque d;
	DequeInit(&d);

	AddFirst(&d, 3);
	AddFirst(&d, 2);
	AddFirst(&d, 1);

	AddLast(&d, 4);
	AddLast(&d, 5);
	AddLast(&d, 6);

	while (!DIsEmpty(&d)) {
		printf("%d", RemoveFirst(&d));
	}
	printf("\n");

	AddLast(&d, 4);
	AddLast(&d, 5);
	AddLast(&d, 6);
	
	AddFirst(&d, 3);
	AddFirst(&d, 2);
	AddFirst(&d, 1);

	while (!DIsEmpty(&d)) {
		printf("%d", RemoveLast(&d));
	}
	printf("\n");

}