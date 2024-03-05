<<<<<<< HEAD
#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
	}
	
	(plist->numOfData)++;
}

void LInsert(List* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	//fundamentals
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
=======
#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
	}
	
	(plist->numOfData)++;
}

void LInsert(List* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	//fundamentals
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
>>>>>>> 6ab67ea156ce834741f47cbb7e3d944c094da48d
}