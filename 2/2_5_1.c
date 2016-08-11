#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int printNodes(struct Node* head){
	while(head != NULL){
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int add(struct Node* node1, struct Node* node2, struct Node* head){

	struct Node* temp = NULL;
	int ret = 0;

	if(node1 == NULL && node2 == NULL){
		head->next = NULL;
		return ret;	
	}

	temp = (struct Node*)malloc(sizeof(struct Node));
	head->next = temp;

	temp->data = ret;

	if(node1 != NULL){
		temp->data += node1->data;
		node1 = node1->next;
	}

	if(node2 != NULL){
		temp->data += node2->data;
		node2 = node2->next;
	}

	temp->data += add(node1, node2, temp);

	if(temp->data >= 10){
		ret = temp->data/10;
		temp->data %= 10;
	}

	return ret;

}

int main(){
	
	struct Node node6 = {7, NULL};
	struct Node node5 = {1, &node6};
	struct Node node4 = {6, &node5};
	struct Node node3 = {5, NULL};
	struct Node node2 = {9, &node3};
	struct Node node1 = {2, &node2};

	printNodes(&node4);
	printNodes(&node1);

	struct Node head;
	add(&node1, &node4, &head);

	printNodes(head.next);

	return 0;
}
