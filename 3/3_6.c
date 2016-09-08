#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

struct Stack {
	int data[STACK_SIZE];
	int top;
};

int push(struct Stack *stack, int value)
{
	if (stack->top >= STACK_SIZE) {
		fprintf(stderr, "The stack is full.\n");
		return -1;
	}

	stack->data[++stack->top] = value;

	return 0;
}

int pop(struct Stack *stack)
{
	if (stack->top < 0) {
		fprintf(stderr, "The stack is empty.\n");
		return -999;
	}

	return stack->data[stack->top--];
}

int peek(struct Stack *stack)
{
	if (stack->top < 0) {
		return -999;
	}

	return stack->data[stack->top];
}

struct Stack * initStack()
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	if (stack == NULL) {
		fprintf(stderr, "initStack error.\n");
		return NULL;
	}
	stack->top = -1;
	return stack;
}

int sort(struct Stack *stack)
{
	struct Stack *temp = initStack();

	while (peek(stack) != -999) {
		int i = pop(stack);
		while (peek(temp) != -999 && peek(temp) < i) {
			push(stack, pop(temp));
		}
		push(temp, i);
	}

	while (peek(temp) != -999) {
		push(stack, pop(temp));
	}

	return 0;
}

int print(struct Stack *stack)
{
	int i = 0;
	printf("BUTTOM->TOP ");
	while (i <= stack->top) {
		printf("%3d ", stack->data[i++]);
	}
	printf("\n");

	return 0;
}

int main()
{
	struct Stack *stack = initStack();

	push(stack, 7);
	push(stack, 10);
	push(stack, 12);
	push(stack, 8);
	push(stack, 5);
	push(stack, 1);
	push(stack, 3);

	print(stack);

	sort(stack);

	print(stack);

	return 0;
}
