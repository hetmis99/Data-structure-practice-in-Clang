#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2) {
		return 0;
	}
	else return 1;
}

int main() {
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);
}