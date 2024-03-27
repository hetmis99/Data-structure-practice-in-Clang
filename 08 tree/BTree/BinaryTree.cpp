#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode() {
	BTreeNode* newnode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

BTData GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL) {
		free(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL) {
		free(main->right);
	}

	main->right = sub;
}

void InorderTraverse(BTreeNode* bt, VIsitFuncPtr action) {
	if (bt == NULL) {
		return;
	}

	InorderTraverse(bt->left,action);
	action(bt -> data);
	InorderTraverse(bt->right,action);
}

void PreorderTraverse(BTreeNode* bt, VIsitFuncPtr action) {
	if (bt == NULL) {
		return;
	}

	printf("%d", bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VIsitFuncPtr action) {
	if (bt == NULL) {
		return;
	}

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteTree(BTreeNode* bt) {
	if (bt == NULL) {
		return;
	}

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("deleted %d\n", bt->data);
	free(bt);
}