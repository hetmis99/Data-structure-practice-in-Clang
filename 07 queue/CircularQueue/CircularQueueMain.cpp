#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CircularQueue.h"

int main() {
	Queue q;
	QueueInit(&q);

	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	EnQueue(&q, 4);
	EnQueue(&q, 5);

	while (!QIsEmpty(&q)) {
		printf("%d", DeQueue(&q));
	}

	return 0;
}
