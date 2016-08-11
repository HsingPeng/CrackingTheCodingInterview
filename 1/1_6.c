/**
  * 00 03 33 30
  * 01 13 32 20
  * 11 12 22 21
  *
  * i j
  * j n-i
  * n-i n-j
  * n-j i
**/
#include <stdio.h>
#define N 5

int main()
{
	int matrix[N][N] = 
	{
		{ 1, 2, 3, 4, 100},
		{ 5, 6, 7, 8, 101},
		{ 9, 10, 11, 12, 102},
		{ 13, 14, 15, 16, 103},
		{ 17, 18, 19, 20, 104}
	};


	print_matrix(matrix, N);

	rotate(matrix, N);

	print_matrix(matrix, N);

	return 0;
}

int print_matrix(int **matrix, int n)
{
	int i = 0, j = 0;

	while(i < n){
		while(j < n){
			//printf("%d %d ", i, j);
			printf("%d ", ((int*)matrix + n*i)[j++]);
		}
		printf("\n");
		i++;
		j = 0;
	}
	printf("\n");
	return 0;
}

int * getEntry(int ** matrix, int x, int y, int n)
{
	return ((int*)matrix + n*x) + y;
}

int rotate(int ** matrix, int n)
{
	int temp,i = 0, j = 0;
	
	n--;

	while(i < (n+1)/2 ){
		while(j < ((n-2*i) + i ) ){
			temp = *getEntry(matrix, i, j, n+1);
			*getEntry(matrix, i, j, n+1) = *getEntry(matrix, n-j, i, n+1);
			*getEntry(matrix, n-j, i, n+1) = *getEntry(matrix, n-i, n-j, n+1);
			*getEntry(matrix, n-i, n-j, n+1) = *getEntry(matrix, j, n-i, n+1);
			*getEntry(matrix, j, n-i, n+1) = temp;
			//printf("%d %d %d\n", i, j, temp);
			j++;
		}
		i++;
		j = i;
	}

	return 0;
}
