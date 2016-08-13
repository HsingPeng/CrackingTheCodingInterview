#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Result {
	struct Node *node;
	int flag;
};

struct Result *isPalindrome(struct Node *head, int length)
{

	struct Result *result = (struct Result *)malloc(sizeof(struct Result));

	if (length == 1) {
		result->node = head->next;
		result->flag = 1;
	} else if (length == 0) {
		result->node = NULL;
		result->flag = 1;
	} else {
		free(result);
		result = isPalindrome(head->next, length - 2);
		if (result->flag == 1) {
			if (result->node != NULL) {
				if (head->data != result->node->data) {
					result->flag = 0;
				}
				result->node = result->node->next;
			} else {
				if (head->data != head->next->data) {
					result->flag = 0;
				}
				result->node = result->node->next;
			}
		}else{
			result->flag = 0;
		}
	}

	return result;
}

int main()
{
	struct Node node5 = {0, NULL};
	struct Node node4 = {1, &node5};
	struct Node node3 = {2, &node4};
	struct Node node2 = {1, &node3};
	struct Node node1 = {0, &node2};

	int length = 0;
	struct Node *temp = &node1;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}

	struct Result *result = isPalindrome(&node1, length);

	printf("isPalindrome -> %d\n", result->flag);

	return 0;
}
