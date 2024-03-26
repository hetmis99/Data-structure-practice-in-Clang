#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void) {
	BTreeNode* newnode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newnode->left = newnode->right = NULL;
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

void MakeLeftSubTree(BTreeNode* main, BTreeNode* bt) {
	if (main->left != NULL)
		free(main->left);

	main->left = bt;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* bt) {
	if (main->right != NULL)
		free(main->left);

	main->right = bt;
}