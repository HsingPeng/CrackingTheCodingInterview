#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct Node {
	int data;
	struct Node *next;
};

struct Stack {
	struct Node *top;
	struct Stack *next;
	struct Stack *prev;
	unsigned int nodeCount;
};

struct SetOfStacks {
	struct Stack *topStack;
} stacks;

int pop()
{
	struct Stack *temp = stacks.topStack;
	if (temp == NULL) {
		fprintf(stderr, "Stack is empty.\n");
		return -1;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}

	struct Node *topOld = temp->top;
	temp->top = temp->top->next;
	free(topOld);
	temp->nodeCount--;

	if(temp->top == NULL) {
		if (temp->prev == NULL) {
			stacks.topStack == NULL;
		} else {
			temp->prev->next = NULL;
		}
		free(temp);
	}

	return 0;
}

int push(int data)
{
	struct Stack *temp = stacks.topStack;
	if (temp == NULL) {
		temp = (struct Stack *)malloc(sizeof(struct Stack));
		temp->top = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		stacks.topStack = temp;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}

	if (temp->nodeCount == STACK_SIZE) {
		struct Stack *tempNew = (struct Stack *)malloc(sizeof(struct Stack));
		temp->next = tempNew;
		tempNew->next = NULL;
		tempNew->prev = temp;
		tempNew->nodeCount = 0;
		temp = tempNew;
	}

	struct Node *topNew = (struct Node*)malloc(sizeof(struct Node));
	topNew->data = data;
	topNew->next = temp->top;
	temp->top = topNew;
	temp->nodeCount++;

	return 0;
}

int print()
{
	struct Stack *temp = stacks.topStack;
	while (temp != NULL) {
		struct Node *tempNode = temp->top;
		while (tempNode != NULL) {
			printf("%3d ", tempNode->data);
			tempNode = tempNode->next;
		}
		printf("<--|\n");
		temp = temp->next;
	}
	printf("\n");

	return 0;
}

struct Node *removeButtom(struct Stack *temp)
{
	if (temp == NULL) {
		return NULL;
	}

	struct Node *buttomPrev = temp->top;
	struct Node *buttom = temp->top->next;
	if (buttom == NULL) {
		temp->prev->next = NULL;
		free(temp);
		return buttomPrev;
	}
	while (buttom->next != NULL) {
		buttomPrev = buttom;
		buttom = buttom->next;
	}

	buttomPrev->next = NULL;
	struct Node *tempNode = removeButtom(temp->next);
	if (tempNode != NULL) {
		tempNode->next = temp->top;
		temp->top = tempNode;
	} else {
		temp->nodeCount--;
	}
	
	return buttom;
}

int popAt(int index)
{
	struct Stack *temp = stacks.topStack;
	while (index-- > 0) {
		temp = temp->next;
		if(temp == NULL) {
			break;
		}
	}

	if(temp == NULL) {
		fprintf(stderr, "Index not exist.\n");
		return -1;
	}

	struct Node *topOld = temp->top;
	if (temp->next != NULL) {
		temp->top = removeButtom(temp->next);
		temp->top->next = topOld;
	} else {
		temp->top = temp->top->next;
		free(topOld);
		temp->nodeCount--;
	}

	if(temp->top == NULL) {
		if (temp->prev == NULL) {
			stacks.topStack == NULL;
		} else {
			temp->prev->next = NULL;
		}
		free(temp);
	}

	return 0;
}

int main()
{
	stacks.topStack == NULL;

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);
	push(12);
	print();

	pop();print();
	pop();print();
	pop();print();
	pop();print();
	pop();print();
	pop();print();

	push(13);print();
	push(14);print();


	printf("test popAt(int)\n");

	popAt(0);print();
	popAt(0);print();

	return 0;
}
