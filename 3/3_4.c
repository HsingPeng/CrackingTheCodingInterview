#include <stdio.h>

#define N 7

struct Tower {
	int node[N];
	int top;
}tower1, tower2, tower3;

int push(struct Tower *tower, int data)
{
	if (tower->top >= N) {
		fprintf(stderr, "The tower is full.\n");
		return -1;
	}

	tower->node[tower->top++] = data;

	return 0;
}

int pop(struct Tower *tower)
{
	if (tower->top == 0) {
		fprintf(stderr, "The tower is empty.\n");
		return -999;
	}

	return tower->node[--tower->top];
}

int moveDisks(int n, struct Tower *source, struct Tower *dest, struct Tower *buffer)
{
	if (n > 2) {
		moveDisks(n-1, source, buffer, dest);
		moveDisks(1, source, dest, buffer);
		moveDisks(n-1, buffer, dest, source);
	} else if (n == 2) {
		moveDisks(1, source, buffer, dest);
		moveDisks(1, source, dest, buffer);
		moveDisks(1, buffer, dest, source);
	} else if (n == 1) {
		push(dest, pop(source));
		print();
	} else {
		fprintf(stderr, "Invalid n (need: 0 <= n <= N)\n");
		return -1;
	}

	return -1;
}

int print()
{
	int i = N, j = 0;
	while (i-- > 0) {
		j = 0;
		if (tower1.top > i) {
			while (j++ < tower1.node[i]) {
				printf("%d", tower1.node[i]);
			}
			j--;
		}
		while (j++ < N) {
			printf(" ");
		}

		printf(" ");

		j = 0;
		if (tower2.top > i) {
			while (j++ < tower2.node[i]) {
				printf("%d", tower2.node[i]);
			}
			j--;
		}
		while (j++ < N) {
			printf(" ");
		}

		printf(" ");

		j = 0;
		if (tower3.top > i) {
			while (j++ < tower3.node[i]) {
				printf("%d", tower3.node[i]);
			}
			j--;
		}
		while (j++ < N) {
			printf(" ");
		}

		printf("\n");	
	}

	static int count = 0;
	count++;
	printf("TOTAL STEP %d\n", count);

	return 0;
}

int main()
{
	tower1.top = 0;
	tower2.top = 0;
	tower3.top = 0;
	
	int i = 0;
	while (i++ < N) {	
		push(&tower1, N-i+1);
	}

	print();

	moveDisks(N, &tower1, &tower3, &tower2);

	//print();

	return 0;
}
