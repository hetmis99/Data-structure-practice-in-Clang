#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} Node;

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	//input
	while (1) {
		scanf("%d", &readData);
		if (readData < 1) break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	printf("\n");

	//print
	if (head == NULL) {
		printf("no data\n");
	}
	else {
		cur = head;
		printf("%d\n", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d\n", cur->data);
		}
	}

	//free
	if (head == NULL) {
		return 0;
	}
	else {
		cur = head;

		free(cur);
		while (cur->next != NULL) {
			cur = cur->next;
			cur->next = cur->next->next;

			free(cur->next);
		}
	}
}
