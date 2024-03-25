#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define TERM 15 // �ֹ� ����

#define CHE_BUR 0 // ġ�����
#define BUL_BUR 1 // �Ұ�����
#define DUB_BUR 2 // �������

#define CHE_TERM 12 // ġ����� ���۽ð�
#define BUL_TERM 15 // �Ұ����� ���۽ð�
#define DUB_TERM 24 // ������� ���۽ð�

int main(){
	int makeproc = 0; // �ܹ��� ���� �����Ȳ
	int cheorder = 0, bulorder = 0, duborder = 0;
	int sec;

	Queue q;
	QueueInit(&q);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++) {
		if (sec % TERM == 0) {
			switch (rand() % 3) {
			case(CHE_BUR): 
				EnQueue(&q, CHE_TERM);
				cheorder++;
				break;
			case(BUL_BUR): 
				EnQueue(&q, BUL_TERM);
				bulorder++;
				break;
			case(DUB_BUR): 
				EnQueue(&q, DUB_TERM);
				duborder++;
				break;
			}
		}

		if (makeproc <= 0 && !QIsEmpty(&q))
			makeproc = DeQueue(&q);
		makeproc--;
	}

	printf("Simulation Report! \n");
	printf(" - Cheese burger: %d \n", cheorder); 
	printf(" - Bulgogi burger: %d \n", bulorder);
	printf(" - Double burger: %d \n", duborder);
	printf(" - Waiting room size: %d \n", QUE_LEN);
}