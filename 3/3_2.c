#include <stdio.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int stackMin[STACK_SIZE];
int top = -1;
int topMin = -1;

int pop()
{
	if (top < 0) {
		printf("stack is empty.\n");
		return -9999;
	}

	if (stack[top] == stackMin[topMin]) {
		topMin--;
	}

	return stack[top--];
}

int push(int node)
{
	if (top == STACK_SIZE) {
		printf("Stack is full.\n");
		return -1;
	}

	if (topMin == -1 || node <= stackMin[topMin]) {
		stackMin[++topMin] = node;
	}

	stack[++top] = node;

	return 0;
}

int min()
{
	if (topMin < 0) {
		printf("Stack is empty.\n");
		return -9999;
	}

	return stackMin[topMin];
}

int print()
{
	int temp = 0;
	while (temp <= top) {
		printf("%d ", stack[temp]);
		temp++;
	}
	
	printf("min = %d\n", min());

	return 0;
}

int main()
{
	push(5);print();
	push(6);print();
	push(3);print();
	push(7);print();
	pop();print();
	pop();print();

	return 0;
}
