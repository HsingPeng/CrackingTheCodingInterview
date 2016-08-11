#include <stdio.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node* findR7(struct Node* head){
	struct Node* p = head;
	struct Node* q = head;

	int i = 0;
	while(i++ < 6){
		q = q->next;
		if(q == NULL){
			return NULL;
		}
	}

	while(q->next != NULL){
		p = p->next;
		q = q->next;
	}

	return p;
}

int main(){
	struct Node node9 = {9, NULL};
	struct Node node8 = {8, &node9};
	struct Node node7 = {7, &node8};
	struct Node node6 = {6, &node7};
	struct Node node5 = {5, &node6};
	struct Node node4 = {4, &node5};
	struct Node node3 = {3, &node4};
	struct Node node2 = {2, &node3};
	struct Node node1 = {1, &node2};

	struct Node* nodeR7 = findR7(&node1);
	printf("nodeR7 -> %d\n", nodeR7->data);

	return 0;
}

