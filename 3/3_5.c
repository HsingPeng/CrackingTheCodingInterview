#include <stdio.h>

#define STACK_SIZE 5

struct Stack {
	int data[STACK_SIZE];
	int top;
};

struct MyQueue {
	struct Stack stackNew, stackOld;
	char last;
} myQueue;

int pop(struct Stack *stack)
{
	if (stack->top < 0) {
		fprintf(stderr, "The stack is empty.\n");
		return -999;
	}
	return stack->data[stack->top--];
}

int push(struct Stack *stack, int data)
{
	if (stack->top >= STACK_SIZE) {
		fprintf(stderr, "The stack is full.\n");
		return -1;
	}
	stack->data[++stack->top] = data;
	return 0;
}

int moveTo(struct Stack *source, struct Stack *dest)
{
	int i = source->top;
	dest->top = -1;
	while (i >= 0) {
		push(dest, pop(source));
		i--;
	}

	return 0;
}

int EnQueue(struct MyQueue *queue, int data)
{
	switch (queue->last) {
		case 'e':
			break;
		case 'd':
			moveTo(&queue->stackOld, &queue->stackNew);
			break;
		default:
			return -1;
			break;
	}
	push(&queue->stackNew, data);
	queue->last = 'e';
	return 0;
}

int DeQueue(struct MyQueue *queue)
{
	switch (queue->last) {
	case 'e':
		moveTo(&queue->stackNew, &queue->stackOld);
		break;
	case 'd':
		break;
	default:
		return -1;
		break;
	}
	queue->last = 'd';
	return pop(&queue->stackOld);
}

int print(struct MyQueue *queue)
{
	int i;
	struct Stack *stack;
	switch (queue->last) {
	case 'e':
		stack = &queue->stackNew;
		i = stack->top;
		printf("HEAD <- ");
		while (i >= 0) {
			printf("%d ", stack->data[i--]);
		}
		printf("\n");
		break;
	case 'd':
		stack = &queue->stackOld;
		i = 0;
		printf("HEAD <- ");
		while (i <= stack->top) {
			printf("%d ", stack->data[i++]);
		}
		printf("\n");
		break;
	default:
		return -1;
		break;
	}

	return 0;
}

int main()
{
	myQueue.last = 'e';
	myQueue.stackNew.top = -1;
	myQueue.stackOld.top = -1;

	EnQueue(&myQueue, 1);
	printf("en 1 ");
	print(&myQueue);
	EnQueue(&myQueue, 2);
	printf("en 2 ");
	print(&myQueue);
	EnQueue(&myQueue, 3);
	printf("en 3 ");
	print(&myQueue);
	EnQueue(&myQueue, 4);
	printf("en 4 ");
	print(&myQueue);
	DeQueue(&myQueue);
	printf("de ");
	print(&myQueue);
	EnQueue(&myQueue, 5);
	printf("en 5 ");
	print(&myQueue);
	DeQueue(&myQueue);
	printf("de ");
	print(&myQueue);
	DeQueue(&myQueue);
	printf("de ");
	print(&myQueue);

	return 0;
}
