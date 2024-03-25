#include <stdlib.h>
#include "DequeBaseQueue.h"

void QueueInit(Queue* pq) {
	DequeInit(pq);
}
int IsEmpty(Queue* pq) {
	return DIsEmpty(pq);
}

void Enqueue(Queue* pq, Data data) {
	AddLast(pq, data);
}

Data Dequeue(Queue* pq) {
	return RemoveFirst(pq);
}

Data QPeek(Queue* pq) {
	return GetFirst(pq);
}