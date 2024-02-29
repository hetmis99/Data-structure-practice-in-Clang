#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

typedef int LData;

typedef struct ArrayList {
	LData arr[100];
	int numOfData;
	int curPosition;
}List;

void ListInit(List* plist) {
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List* plist, LData data) {
	if (plist->numOfData >= LIST_LEN) return;
	plist->arr[plist->numOfData++] = data;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0) {
		return FALSE;
	}
	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= plist->numOfData - 1) {
		return FALSE;
	}

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];

	for (int i = rpos; i < num - 1; i++) {
		plist->arr[i] = plist->arr[i + 1];
	}
	
	plist->numOfData--;
	plist->curPosition--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

int main() {
	List list;
	ListInit(&list);
	int data, sum = 0;

	for (int i = 1; i <= 9; i++) {
		LInsert(&list, i);
	}

	if (LFirst(&list, &data)) {
		sum += data;

		while (LNext(&list, &data)) {
			sum += data;
		}
	}
	printf("%d", sum);

	if (LFirst(&list, &data)) {
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0) {
				LRemove(&list);
			}
		}
	}

	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}
}