#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _dlDeque {
	Node* head;
	Node* tail;
}DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pd);
int DIsEmpty(Deque* pd);

void AddFirst(Deque* pd, Data data);
void AddLast(Deque* pd, Data data);
Data RemoveFirst(Deque* pd);
Data RemoveLast(Deque* pd);
Data GetFirst(Deque* pd);
Data GetLast(Deque* pd);

#endif