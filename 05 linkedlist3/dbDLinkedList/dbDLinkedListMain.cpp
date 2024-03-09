#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dbDLinkedList.h"

int main() {
	List list;
	int data;
	ListInit(&list);

	for (int i = 1; i <= 8; i++) {
		LInsert(&list, i);
	}
	
	//browse
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n");

	//remove multiple of 2
	if (LFirst(&list, &data)) {
		if (data % 2 == 0) {
			LRemove(&list);
		}
		while (LNext(&list, &data)) {
			if (data % 2 == 0) {
				LRemove(&list);
			}
		}
	}

	//browse
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}

