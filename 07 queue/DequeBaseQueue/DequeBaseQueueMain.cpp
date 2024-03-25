#include <stdio.h>
#include "DequeBaseQueue.h"

int main() {
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!IsEmpty(&q)) {
		printf("%d", Dequeue(&q));
	}
	return 0;
}