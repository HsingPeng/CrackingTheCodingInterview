#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
  * arr[4] : 0 ~ 3 middle=2 : 0 ~ 1 2 ~ 3 : 0 1 2 3
  * arr[3] : 0 ~ 2 middle=1 : 0 ~ 1 2     : 0 1 2
**/
struct TreeNode *createMinimalBST(int arr[], int start, int end)
{
	int mid = (end + start + 1) / 2;
	struct TreeNode *n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	n->data = arr[mid];
	
	if (start < mid) {	
		n->left = createMinimalBST(arr, start, mid-1);
	} else {
		n->left = NULL;
	}

	if (mid < end) {
		n->right = createMinimalBST(arr, mid+1, end);
	} else {
		n->right = NULL;
	}

	return n;
}

int print(struct TreeNode *root)
{
	if (root == NULL) {
		return 0;
	}

	printf("%2d ", root->data);

	print(root->left);
	print(root->right);

	return 0;
}

int main()
{
	int arr[] = {1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	struct TreeNode *root = createMinimalBST(arr, 0, 11);
	print(root);
	printf("\n");

	return 0;
}
