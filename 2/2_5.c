#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int printNodes(struct Node* head){
	while(head != NULL){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
	return 0;
}

struct Node* add(struct Node* head1, struct Node* head2, struct Node* head, int lastNum){
	
	if(head1 == NULL && head2== NULL){
		return head;
	}

	struct Node* temp = (struct Node*)malloc(sizeof (struct Node));

	temp->data = lastNum;
	if(head1 != NULL){
		temp->data += head1->data;
	}
	if(head2 != NULL){
		temp->data += head2->data;
	}
	head==NULL ? (head=temp) : (head->next=temp);

	if(temp->data >= 10){
		int sum = temp->data;
		temp->data %= 10;
		add(head1->next, head2->next, temp, sum/10);
	}else{
		add(head1->next, head2->next, temp, 0);
	}

	return temp;
}

int main(){
	
	struct Node node6 = {6, NULL};
	struct Node node5 = {1, &node6};
	struct Node node4 = {7, &node5};
	struct Node node3 = {2, NULL};
	struct Node node2 = {9, &node3};
	struct Node node1 = {5, &node2};

	printNodes(&node1);
	printNodes(&node4);

	struct Node* head = add(&node1, &node4, NULL, 0);

	printNodes(head);

	return 0;
}
