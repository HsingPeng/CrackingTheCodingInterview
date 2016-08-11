#include <stdio.h>

struct Node {
	char data;
	struct Node *next;
};

struct Node *findHeadNode(struct Node *node1)
{
	struct Node *slowNode, *fastNode;
	
	slowNode = node1;
	fastNode = node1;

	while (slowNode != NULL && fastNode != NULL && fastNode->next != NULL) {
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
		if (slowNode == fastNode) {
			break;
		}
	}

	if (slowNode == fastNode) {
		slowNode = node1;
	} else {
		return NULL;
	}

	while (slowNode != NULL && fastNode != NULL) {
		slowNode = slowNode->next;
		fastNode = fastNode->next;
		if (slowNode == fastNode) {
			break;
		}
	}

	if (slowNode != fastNode) {
		return NULL;
	}

	return fastNode;
}

int main()
{
	struct Node node3;
	struct Node node5 = {'E', &node3};
	struct Node node4 = {'D', &node5};
	node3.data = 'C';node3.next = &node4;
	struct Node node2 = {'B', &node3};
	struct Node node1 = {'A', &node2};

	struct Node *headNode = findHeadNode(&node1);

	printf("HeadNode -> %c\n", headNode->data);

	return 0;
}
