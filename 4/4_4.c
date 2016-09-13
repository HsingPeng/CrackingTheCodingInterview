#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct Tree {
	struct TreeNode *root;
};

struct ListNode {
	struct TreeNode *value;
	struct ListNode *next;
};

struct List {
	struct ListNode *first;
	struct ListNode *last;
	struct List *next;
};

struct Lists {
	struct List *first;
	struct List *last;
};

struct List *createList()
{
	struct List *list = (struct List *)malloc(sizeof(struct List));

	if (list == NULL) {
		fprintf(stderr, "Create list error.\n");
		return NULL;
	}

	list->first == NULL;
	list->last == NULL;
	return list;
}

int addListNode(struct List *list, struct TreeNode *value)
{

	if (value == NULL) {
		return 0;
	}

	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (node == NULL) {
		fprintf(stderr, "addListNode(): malloc node error.\n");
		return -1;
	}
	node->value = value;
	node->next = NULL;

	if (list->first == NULL) {
		list->first = node;
	} else {
		list->last->next = node;
	}
	list->last = node;

	return 0;
}

/**
  * int flag: 0:get node from the first ; 1:follow the previous get;
  * return: NULL means the end of the list.
**/
struct ListNode *getNode(struct List *list, int flag)
{
	static struct ListNode *prev = NULL;
	if (!flag) {
		prev = NULL;
	}

	if (prev == NULL) {
		prev = list->first;
		return prev;
	} else {
		prev = prev->next;
		return prev;
	}
}

inline int isEmptyList(struct List *list)
{
	return list->first == NULL;
}

int printList(struct List *list)
{
	if (list->first == NULL) {
		printf("empty\n");
		return 0;
	}

	struct ListNode *temp = list->first;
	while (temp != NULL) {
		printf("%2d -> ", temp->value->data);
		temp = temp->next;
	}
	printf("NULL\n");

	return 0;
}

int addLists(struct Lists *lists, struct List *list)
{
	if (lists->first == NULL) {
		lists->first = list;
	} else {
		lists->last->next = list;
	}
	lists->last = list;

	return 0;
}

struct Lists *createLevelLinkedList(struct Tree *tree)
{
	struct Lists *lists = (struct Lists *)malloc(sizeof(struct Lists));
	if (lists == NULL) {
		fprintf(stderr, "createLevelLinkedList():malloc lists error.\n");
		return NULL;
	}
	lists->first = NULL;
	lists->last = NULL;

	if (tree->root == NULL) {
		return lists;
	}

	struct List *current = createList();
	addListNode(current, tree->root);

	while (!isEmptyList(current)) {
		addLists(lists, current);

		struct List *parent = current;
		current = createList();
		struct ListNode *node = NULL;
		while ((node = getNode(parent, 1)) != NULL) {
			addListNode(current, node->value->left);
			addListNode(current, node->value->right);
		}	
	}

	return lists;
}

/**
  *           7
  *     4           10
  *  2     6    9       11
  * 1 3   5    8      12
**/
int main()
{
	struct Tree tree;
	struct TreeNode node1 = {1, NULL, NULL};
	struct TreeNode node3 = {3, NULL, NULL};
	struct TreeNode node2 = {2, &node1, &node3};
	struct TreeNode node5 = {5, NULL, NULL};
	struct TreeNode node6 = {6, &node5, NULL};
	struct TreeNode node4 = {4, &node2, &node6};
	struct TreeNode node8 = {8, NULL, NULL};
	struct TreeNode node9 = {9, &node8, NULL};
	struct TreeNode node12 = {12, NULL, NULL};
	struct TreeNode node11 = {11, &node12, NULL};
	struct TreeNode node10 = {10, &node9, &node11};
	struct TreeNode root = {7, &node4, &node10};
	tree.root = &root;
	
	struct Lists *lists = createLevelLinkedList(&tree);
	
	struct List *temp = lists->first;
	while (temp != NULL) {
		printList(temp);
		temp = temp->next;
	}

	return 0;
}
