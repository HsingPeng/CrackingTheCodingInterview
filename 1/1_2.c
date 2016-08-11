#include <stdio.h>
#include <string.h>

int reverse(char *);

int main()
{
	char string[] = "abcdefghijk!" ;
	printf("before => %s\n", string);
	reverse(string);
	printf("after => %s\n", string);
	return 0;
}

int reverse(char * string)
{
	char temp;

	int i =0;
	int sum = strlen(string) - 1;

	for(; i < sum/2 ; i++){
		temp = string[i];
		string[i] = string[sum - i];
		string[sum - i] = temp;
	}

	return 0;
}
