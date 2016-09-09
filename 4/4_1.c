#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode *lChild;
	struct TreeNode *rChild;
};

/**
  * Return: -1 unbalance; >=1 height;
  *
**/
int isBalance(struct TreeNode *tree)
{

	if (tree == NULL) {
		return 0;
	}

	int lHeight = isBalance(tree->lChild);
	if (lHeight == -1) {
		return -1;
	}

	int rHeight = isBalance(tree->rChild);
	if (rHeight == -1) {
		return -1;
	}

	if (lHeight - rHeight >= -1 && lHeight - rHeight <= 1) {
		return (lHeight>rHeight?lHeight:rHeight) + 1;
	} else {
		return -1;
	}
}

int main()
{

	//struct TreeNode node0 = {0, NULL, NULL};
	struct TreeNode node1 = {1, NULL/*&node0*/, NULL};
	struct TreeNode node2 = {2, &node1, NULL};
	struct TreeNode node3 = {3, NULL, NULL};
	struct TreeNode node4 = {4, &node2, &node3};
	struct TreeNode node5 = {5, NULL, NULL};
	struct TreeNode node6 = {6, &node5, NULL};
	struct TreeNode node7 = {7, NULL, NULL};
	struct TreeNode node8 = {8, &node6, &node7};
	struct TreeNode node9 = {9, &node4, &node8};

	if (isBalance(&node9) != -1) {
		printf("Balance.\n");
	} else {
		printf("Unbalance.\n");
	}

	return 0;
}
