/**
  *程序有bug，对于重复10次以上的情况，空间会判断错误
  *
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * compress(char *);

int main()
{
	char str[] = "abcccdddeeefff";
	
	printf("before => %s\n", str);

	char * str_new = compress(str);

	printf("after ==> %s\n", str_new);

	return 0;
}

char * compress(char * str)
{
	int size1 = strlen(str);
	int size2 = 0;

	int i = 0, accum = 1;
	
	while(++i < size1){
		if(str[i] == str[i-1]){
		}else{
			size2 += 2;
		}
	}
	size2 += 2;

	if(size1 < size2){
		return str;
	}

	i = 0;
	accum = 1;
	int j = 0;
	char * str_new = (char*)malloc( sizeof(char) * size2 );

	while(++i < size1){
		if( str[i] == str[i-1] ){
			accum++;
		}else{
			str_new[j++] = str[i-1];
			str_new[j++] = accum + '0';
			accum = 1;
		}
	}
	
	str_new[j++] = str[i-1];
	str_new[j++] = accum + '0';
	
	return str_new;
}
