#include <stdio.h>

struct Node {
	int data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
};

struct Node *inorderSucc(struct Node *n)
{
	if (n == NULL) {
		return NULL;
	}

	if (n->right != NULL) {
		n = n->right;
		while (n->left != NULL) {
			n = n->left;
		}

		return n;
	}

	if (n->parent == NULL) {
		return NULL;
	}

	if (n->parent->left == n) {
		return n->parent;
	}

	while (n->parent != NULL && n->parent->left != n) {
		n = n->parent;
	}

	return n->parent;
}

/**
  *           7
  *     4           10
  *  2     6    9       11
  * 1 3   5    8      12
**/
int main()
{
	struct Node node1 = {1, NULL, NULL, NULL};
	struct Node node3 = {3, NULL, NULL, NULL};
	struct Node node2 = {2, NULL, &node1, &node3};
	struct Node node5 = {5, NULL, NULL, NULL};
	struct Node node6 = {6, NULL, &node5, NULL};
	struct Node node8 = {8, NULL, NULL, NULL};
	struct Node node9 = {9, NULL, &node8, NULL};
	struct Node node12 = {12, NULL, NULL, NULL};
	struct Node node11 = {11, NULL, &node12, NULL};
	struct Node node4 = {4, NULL, &node2, &node6};
	struct Node node10 = {4, NULL, &node9, &node11};
	struct Node root = {7, NULL, &node4, &node10};

	node1.parent = &node2;
	node3.parent = &node2;
	node2.parent = &node4;
	node5.parent = &node6;
	node6.parent = &node4;
	node8.parent = &node9;
	node9.parent = &node10;
	node12.parent = &node11;
	node11.parent = &node10;
	node4.parent = &root;
	node10.parent = &root;

	struct Node *node = &node1;
	struct Node *nodeNext = inorderSucc(node);

	printf("      +-----7-------+\n      |             |\n   +--4----+    +--10--+\n   |       |    |      |\n +-2-+   +-6  +-9    +-11\n |   |   |    |      |\n 1   3   5    8     12\n");

	printf("Node = %d\n", node->data);

	if (nodeNext != NULL) {
		printf("nodeNext = %d\n", nodeNext->data);
	} else {
		printf("Not exist.\n");
	}

	return 0;
}
