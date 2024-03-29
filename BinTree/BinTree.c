#include "BinTree.h"

nodePtr createNode(int key) {
	nodePtr newNode = (nodePtr)malloc(sizeof(node));

	newNode->key = key;
	newNode->left = newNode->right = NULL;

	return newNode;
}

/* recursive version */
nodePtr insertNodeRecur(nodePtr root, int key) {
	if (!root)
		return createNode(key);

	switch (INTCMP(key, root->key)) {
	case -1:
		root->left = insertNodeRecur(root->left, key);
	case 0:
		return NULL;
	case 1:
		root->right = insertNodeRecur(root->right, key);
	}
}

void printTree(nodePtr root) {
	if (!root)
		return;

	printTree(root->left);
	printf("%d ", root->key);
	printTree(root->right);
}

void demolishTreeRecur(nodePtr root) {
	if (!root)
		return;

	demolishTreeRecur(root->left);
	demolishTreeRecur(root->right);
	free(root);
}