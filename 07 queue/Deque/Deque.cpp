#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pd) {
	pd->head = pd->tail = NULL;
}

int DIsEmpty(Deque* pd) {
	return pd->head == NULL;
}

void AddFirst(Deque* pd, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = pd->head;
	newnode->data = data;
	if (DIsEmpty(pd)) pd->tail = newnode;
	else {
		pd->head->prev = newnode;
	}
	newnode->prev = NULL;
	pd->head = newnode;
}

void AddLast(Deque* pd, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->prev = pd->tail;
	newnode->data = data;
	if (DIsEmpty(pd)) pd->head = newnode;
	else {
		pd->tail->next = newnode;
	}
	newnode->next = NULL;
	pd->tail = newnode;
}
Data RemoveFirst(Deque* pd) {
	if (DIsEmpty(pd)) exit(-1);
	Data rdata;
	Node* tmp = pd->head;
	rdata = tmp->data;
	pd->head = tmp->next;
	free(tmp);

	// 추가된 부분
	if (pd->head == NULL)
		pd->tail = NULL;
	else {
		pd->head->prev = NULL;
	}
	return rdata;
}
Data RemoveLast(Deque* pd) {
	if (DIsEmpty(pd)) exit(-1);
	Data rdata;
	Node* tmp = pd->tail;
	rdata = tmp->data;
	pd->tail = tmp->prev;
	free(tmp);

	//추가된 부분
	if (pd->tail == NULL)
		pd->head = NULL;
	else {
		pd->tail->next = NULL;
	}
	return rdata;
}
Data GetFirst(Deque* pd) {
	if (DIsEmpty(pd)) exit(-1);
	return pd->head->data;
}
Data GetLast(Deque* pd) {
	if (DIsEmpty(pd)) exit(-1);
	return pd->tail->data;
}