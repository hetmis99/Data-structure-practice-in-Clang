#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = plist->head;

	if (plist->head != NULL) {
		plist->head->prev = newnode;
	}
	newnode->prev = NULL;
	plist->head = newnode;

	(plist->numOfData)++;
};

int LFirst(List* plist, Data* pdata) {
	if (plist->head == NULL) {
		return FALSE;
	}
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
};

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == NULL) {
		return FALSE;
	}
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
};

int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == NULL) {
		return FALSE;
	}
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
};

int LCount(List* plist) {
	return plist->numOfData;
}