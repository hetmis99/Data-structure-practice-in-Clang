#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode();
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);
typedef void (*VIsitFuncPtr)(BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void InorderTraverse(BTreeNode* bt, VIsitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VIsitFuncPtr action);
void PreorderTraverse(BTreeNode* bt, VIsitFuncPtr action);
void DeleteTree(BTreeNode* bt);

#endif
