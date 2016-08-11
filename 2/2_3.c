#include <stdio.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* delete(struct Node* p){
	p->data = p->next->data;
	p->next = p->next->next;
	return p;
}

int printNodes(struct Node* head){
	while(head->next != NULL){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main(){

	struct Node node7 = {7, NULL};
	struct Node node6 = {6, &node7};
	struct Node node5 = {5, &node6};
	struct Node node4 = {4, &node5};
	struct Node node3 = {3, &node4};
	struct Node node2 = {2, &node3};
	struct Node node1 = {1, &node2};

	printNodes(&node1);
	delete(&node4);
	printNodes(&node1);

	return 0;
}

