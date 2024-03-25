#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int IsEmpty(Queue* pq) {
	if (pq->front == NULL) return TRUE;
	return FALSE;
}

void Enqueue(Queue* pq, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->data = data;

	if (IsEmpty(pq)) {
		pq->front = pq->rear = newnode;
	}
	else {
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
}

Data Dequeue(Queue* pq) {
	if (IsEmpty(pq)) exit(-1);
	Data rdata;
	Node* tmp = pq->front;
	rdata = tmp->data;
	pq->front = tmp->next;
	free(tmp);
	return rdata;
}

Data QPeek(Queue* pq) {
	if (IsEmpty(pq)) exit(-1);
	return pq->front->data;
}
