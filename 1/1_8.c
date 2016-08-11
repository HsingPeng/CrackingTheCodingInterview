#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[] = "abcdefg";
	char str2[] = "efgabcd";

	if(isRotation(str1, str2)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
}

int isRotation(char * str1, char * str2)
{
	char * temp = (char*)malloc( strlen(str1)*2*sizeof(char) );
	//strcat有坑，dest必须提前分配好足够空间，否则会越界
	strcpy(temp, str2);
	strcat(temp, str2);

	if( strstr(temp, str1) == NULL ){
		return 0;
	}

	return 1;
}
