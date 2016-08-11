/**
  *C语言细节繁琐，所以看上去加大了时间复杂读
  *打印会有M×N，数组初始化有M+N
**/

#include <stdio.h>

#define M 4
#define N 5

int main()
{
	int matrix[M][N] = {
		{1, 2, 3, 4, 5},
		{6, 7, 0, 9, 1},
		{1, 2, 3, 0, 5},
		{6, 7, 8, 9, 2}
	};

	print_matrix(matrix, M, N);

	setZeros(matrix, M, N);

	print_matrix(matrix, M, N);
	
	return 0;
}

int * getEntry(int ** matrix, int x, int y, int n)
{
	return (int*)matrix + x*n + y;
}

int print_matrix(int ** matrix, int m, int n)
{
	int i=0, j=0;

	for(; i < m; i++){
		for(j=0 ; j < n; j++){
			printf("%d ", *getEntry(matrix, i, j, n));
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

int setZeros(int ** mat, int m, int n)
{
	int row[m];	//行
	int column[n];	//列
	
	int i=0, j=0;

	for(i=0; i < m; i++){
		row[i] = 0;
	}

	for(i=0; i<n ; i++){
		column[i] = 0;
	}

	for(i=0; i < m; i++){
		for(j=0; j < n; j++){
			if(! *getEntry(mat, i, j, n) ){
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	//下面不是最优解决，可以循环M*N次，针对元素判断，用row[i]|colum[j]

	for(i=0; i < m; i++){
		if( row[i] ){
			for(j=0; j < n; j++){
			*getEntry(mat, i, j, n) = 0;
			}
		}
	}
	for(i=0; i < n; i++){
		if( column[i] ){
			for(j=0; j < m; j++){
			*getEntry(mat, j, i, n) = 0;
			}
		}
	}

	return 0;
}
