#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int RecursiveBsearch(int arr[], int f, int l, int target) {
	int mid = (f + l) / 2;
	if (f > l) return -1;

	if (target == arr[mid])return mid;
	else if (target < arr[mid]) {
		RecursiveBsearch(arr, f, mid - 1, target);
	}
	else {
		RecursiveBsearch(arr, mid + 1, l, target);
	}
}
