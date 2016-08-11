#include <stdio.h>
struct Node{
	int data;
	struct Node* next;
};

int sortX(struct Node* head, int x){
	struct Node* beforeEnd = NULL;
	struct Node* beforeStart = NULL;
	struct Node* afterStart = NULL;
	struct Node* temp = NULL;

	while(head != NULL){
		temp = head->next;
		if(head->data > x){
			if(afterStart != NULL){
				head->next = afterStart;
			}else{
				head->next = NULL;
			}
			afterStart = head;
		}else{
			if(beforeEnd != NULL){
				beforeEnd->next = head;
			}else{
				beforeStart = head;
				head->next = NULL;
			}
			beforeEnd = head;
		}
		head = temp;
	}
	
	if(beforeStart != NULL){
		head = beforeStart;
		beforeEnd->next = afterStart;
	}else if(afterStart != NULL){
		head = afterStart;
	}

	return 0;
}

int printNodes(struct Node* head){
	while(head != NULL){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
	
	return 0;
}

int main(){
	
	struct Node node9 = {9, NULL};
	struct Node node8 = {8, &node9};
	struct Node node7 = {7, &node8};
	struct Node node6 = {6, &node7};
	struct Node node5 = {5, &node6};
	struct Node node4 = {4, &node5};
	struct Node node3 = {13, &node4};
	struct Node node2 = {12, &node3};
	struct Node node1 = {1, &node2};

	printNodes(&node1);
	sortX(&node1, 7);
	printNodes(&node1);

	return 0;
}
