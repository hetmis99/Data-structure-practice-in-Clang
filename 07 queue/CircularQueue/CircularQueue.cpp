#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq) {
	pq->front = pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear) return true;
	return false;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1) return 0;
	return pos + 1;
}

void EnQueue(Queue* pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data DeQueue(Queue* pq) {
	Data rdata;
	if (QIsEmpty(pq)) exit(-1);
	else {
		pq->front = NextPosIdx(pq->front);
		return	pq->queArr[pq->front];
	}
}

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) exit(-1);
	else {
		return pq->queArr[pq->front];
	}
}
