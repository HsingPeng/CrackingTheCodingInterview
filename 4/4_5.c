#include <stdio.h>
#include <limits.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

int checkBSTInner(struct Node *current, int min, int max)
{
	if (current == NULL) {
		return 1;
	}

	if (current->data < min || current->data >= max
			|| !checkBSTInner(current->left, min, current->data)
			|| !checkBSTInner(current->right, current->data, max)) {
		return 0;
	}

	return 1;
}

int checkBST(struct Node *root)
{
	return checkBSTInner(root, INT_MIN, INT_MAX);
}

/**
  *           7
  *     4           10
  *  2     6    9       11
**/
int main()
{
	struct Node node2 = {/*2*/12, NULL, NULL};
	struct Node node6 = {6, NULL, NULL};
	struct Node node4 = {4, &node2, &node6};
	struct Node node9 = {9, NULL, NULL};
	struct Node node11 = {11, NULL, NULL};
	struct Node node10 = {10, &node9, &node11};
	struct Node root = {7, &node4, &node10};

	if (checkBST(&root)) {
		printf("YES.\n");
	} else {
		printf("NO.\n");
	}

	return 0;
}
