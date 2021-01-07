#pragma once

#include "BinaryTree.h"

//creats an empty tree
treePtr initBinTree()
{
	return NULL;
}
//creats a tree--> lChild = left, rChild = right, root info = info
treePtr buildBinTree(treePtr lChild, treePtr rChild, itemType info)
{
	treePtr root = (treePtr)malloc(sizeof(treeNode));
	if (!root)
		return NULL;//in case of unseccssefull allocate

	root->info = info;
	root->left = lChild;
	root->right = rChild;
	return root;
}
//return 1 if t empty 0 if not
int isEmptyBinTree(treePtr t)
{
	return t == NULL;
}
//insert the value to the root tree
void insertBinTree(treePtr* root, itemType value)
{
	if (isEmptyBinTree(*root) || value == (*root)->info)
		return;//breaking condition

	if (value < (*root)->info)
	{
		if (isEmptyBinTree((*root)->left))
			(*root)->left = buildBinTree(NULL, NULL, value);
		else
			insertBinTree(&(*root)->left, value);
	}
	else
	{
		if (isEmptyBinTree((*root)->right))
			(*root)->right = buildBinTree(NULL, NULL, value);
		else
			insertBinTree(&(*root)->right, value);
	}
}
//printing in ascending order all the tree nodes in range u <= info <=v
void rangeSearch(treePtr t, itemType u, itemType v)
{
	if (!t)
		return;

	rangeSearch(t->left, u, v);
	if (t->info >= u && t->info <= v)
			visit(t->info); 
		rangeSearch(t->right, u, v);
}
//printing info
void visit(itemType info)
{
	printf("%d ", info);
}
//binary tree "toString"
void printTree(const treePtr root)
{
	if (!root)
		return;//breaking condition
	printTree(root->left);
	printTree(root->right);
}
//free all the dynamic allocations
void freeTree(treePtr root)
{
	if (!root)
		return;
	if (!root->left && !root->right)
		free(root);
	else
	{
		freeTree(root->left);
		freeTree(root->right);
	}
}