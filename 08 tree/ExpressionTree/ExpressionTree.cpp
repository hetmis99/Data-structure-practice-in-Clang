#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ExpressionTree.h"
#include "BinaryTree.h"
#include "ListBaseStack.h"

BTreeNode* MakeExpTree(char exp[]) {
	BTreeNode* newnode;
	Stack s;
	StackInit(&s);
	int len = strlen(exp);

	for (int i = 0; i < len; i++) {
		newnode = MakeBTreeNode();
		if (isdigit(exp[i])) {
			SetData(newnode, exp[i] - '0');
		}
		else {
			MakeRightSubTree(newnode, SPop(&s)); //
			MakeLeftSubTree(newnode, SPop(&s)); // Right�� Left�� ������ ���� ���� ���� ũ�� ������. �Ϲ����� ������ ������ ���� �����Ϸ��� Right�� Left�� ȣ���ؾ���.
			SetData(newnode, exp[i]);
		}

		SPush(&s, newnode);
	}
	return SPop(&s);
}

int EvaluateExpTree(BTreeNode* bt) {
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) return GetData(bt);
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
	case'+':
		return op1 + op2;
	case'-':
		return op1 - op2;
	case'*':
		return op1 * op2;
	case'/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data) {
	if (0<=data && data<=9) 
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt) {
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}