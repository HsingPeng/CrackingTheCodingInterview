#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

struct Stack {
	unsigned int head;
	unsigned int capacity;
	unsigned int size;
} stack1, stack2, stack3;

int stackBuffer[STACK_SIZE];

struct Stack *getStack(int whichStack)
{
	struct Stack *stack;
	switch (whichStack) {
		case 1:
			stack = &stack1;
			break;
		case 2:
			stack = &stack2;
			break;
		case 3:
			stack = &stack3;
			break;
		default:
			stack = NULL;
			break;
	}
	return stack;
}

int moveBefore()
{
	int temp = stack2.head;
	while (temp < stack2.head + stack2.size) {
		stackBuffer[temp - 1] = stackBuffer[temp];
		temp++;
	}
	stack1.capacity--;
	stack2.capacity++;
	stack2.head--;

	return 0;
}

int moveAfter()
{
	int temp = stack2.head + stack2.size - 1;
	while (temp >= stack2.head) {
		stackBuffer[temp + 1] = stackBuffer[temp];
		temp--;
	}
	stack2.capacity++;
	stack2.head++;
	stack3.capacity--;
	stack1.capacity++;
	
	return 0;
}

int expand(int whichStack)
{
	struct Stack *stack = getStack(whichStack);
	if (stack == NULL) {
		fprintf(stderr, "ERROR: expand(): stack == NULL\n");
		return -1;
	}

	if (stack1.size + stack2.size + stack3.size == STACK_SIZE) {
		fprintf(stderr, "ERROR: expand(): FULL\n");
		return -1;
	}

	if(whichStack == 1){
		if (stack2.head - stack1.head > stack1.size) {
			stack1.capacity++;
		} else if (stack3.head - stack2.head + 1 > stack3.size + stack2.size) {
			moveAfter();
		} else {
			fprintf(stderr, "ERROR: expand(): unknown case 13\n");
			exit(1);
		}
	} else if (whichStack == 2) {
		if (stack3.head - stack2.head + 1 > stack3.size + stack2.size) {
			stack2.capacity++;
			stack3.capacity--;
		} else if (stack2.head - stack1.head > stack1.size) {
			moveBefore();
		} else {
			fprintf(stderr, "ERROR: expand(): unknown case 23\n");
			exit(1);
		}
	} else {
		if (stack3.head - stack2.head + 1 > stack3.size + stack2.size) {
			stack2.capacity--;
			stack3.capacity++;	
		} else if (stack2.head - stack1.head > stack1.size) {
			moveBefore();
			stack2.capacity--;
			stack3.capacity++;
		
		} else {
			fprintf(stderr, "ERROR: expand(): unknown case 33\n");
			exit(1);
		}
	}

	return 0;
}

int push(int whichStack, int value)
{
	struct Stack *stack = getStack(whichStack);
	if (stack == NULL) {
		fprintf(stderr, "ERROR: push(): stack == NULL\n");
		return -1;
	}

	if (stack->capacity <= stack->size) {
		printf("INFO: stack%d need to be expanded\n", whichStack);
		if (expand(whichStack)) {
			fprintf(stderr, "ERROR: push(): expand error\n");
			return -1;
		}
	}

	if (whichStack == 3) {
		stackBuffer[stack->head - stack->size] = value;
	} else {
		stackBuffer[stack->head + stack->size] = value;
	}
	stack->size++;

	return 0;
}


int pop(int whichStack)
{	
	struct Stack *stack = getStack(whichStack);
	if (stack == NULL) {
		fprintf(stderr, "ERROR: pop(): stack == NULL\n");
		exit(-1);
	}

	int value;

	if (whichStack == 3) {
		value = stackBuffer[stack->head - stack->size + 1];
	} else {	
		value = stackBuffer[stack->head + stack->size - 1];
	}
	stack->size--;

	return value;
}

int print()
{
	int temp = 0;
	while (temp < STACK_SIZE) {
		if (temp >= stack1.size && temp < stack2.head) {
			printf("_ ");
		} else if (temp >= stack2.head + stack2.size
				&& temp <= stack3.head - stack3.size) {
			printf("= ");
		} else {
			printf("%d ", stackBuffer[temp]);
		}
		temp++;
	}
	printf("\n");

	return 0;
}

int main()
{
	stack1.head = 0;
	stack1.capacity = STACK_SIZE / 3;
	stack1.size = 0;

	stack2.head = STACK_SIZE / 3;
	stack2.capacity = STACK_SIZE / 3;
	stack2.size = 0;

	stack3.head = STACK_SIZE - 1;
	stack3.capacity = STACK_SIZE - stack1.capacity - stack2.capacity;
	stack3.size = 0;

	push(1, 1);
	push(1, 2);
	push(1, 3);

	push(2, 4);
	push(2, 5);
	push(2, 6);

	push(3, 7);
	push(3, 8);
	push(3, 9);


	printf("push 1 2 3 - 4 5 6 - 7 8 9\n");
	print();

	int value = pop(1);
	printf("pop stack1 -> %d\n", value);

	printf("push(2, 17)\n");
	push(2, 17);
	print();

	printf("push(2, 18)\n");
	push(2, 18);
	print();

	printf("push(2, 19)\n");
	push(2, 19);
	print();

	return 0;
}
