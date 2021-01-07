#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int itemType;

typedef struct bTreeNode {
	itemType info;
	struct bTreeNode* right;
	struct bTreeNode* left;
 }treeNode, *treePtr;

//creats an empty tree
treePtr initBinTree();
//creats a tree--> lChild = left, rChild = right, root info = info
treePtr buildBinTree(treePtr lChild, treePtr rChild, itemType info);
//insert the value to the root tree
void insertBinTree(treePtr *root, itemType value);
//return 1 if t empty 0 if not
int isEmptyBinTree(treePtr t);
//printing in ascending order all the tree nodes in range u <= info <=v
void rangeSearch(treePtr t, itemType u, itemType v);
//printing info
void visit(itemType info);
//binary tree "toString"
void printTree(const treePtr root);
//free all the dynamic allocations
void freeTree(treePtr root);