#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] = "Mr John Smith ";

	printf("before => %s\n", str);
	replace(str);
	printf("after => %s\n", str);
	
	return 0;
}

int replace(char * str)
{
	int size1 = strlen(str);

	int extra = 0 , i = 0;

	while(i < size1){
		if( str[i++] == ' ' ){
			extra += 2;
		}
	}

	int size2 = size1 + extra - 1;

	i = size1 -1;

	while(i >= 0){
		if( str[i--] == ' ' ){
			str[size2--] = '0';
			str[size2--] = '2';
			str[size2--] = '%';
		}else{
			str[size2--] = str[i+1];
		}
	}

	return 0;
}
