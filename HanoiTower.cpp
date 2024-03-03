#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Hanoi(int num, char from, char by, char to) {
	if (num == 1) {
		printf("���� 1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		Hanoi(num - 1, from, to, by);
		printf("���� 1�� %c���� %c�� �̵�\n", from, to);
		Hanoi(num - 1, by, from, to);
	}
}