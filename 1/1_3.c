#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "abcdeeefg";
	char str2[] = "dcbafeeeg";

	if( isAnagram(str1, str2) ){
		printf("YES\n");
	}else{
		printf("NO!\n");
	}
	
	return 0;
}

int isAnagram(char * str1, char * str2)
{
	int bitmap[256];

	int i =0 ;
	while(i < 256){
		bitmap[i++] = 0;
	}

	int size1 = strlen(str1);
	int size2 = strlen(str2);

	if(size1 != size2){
		return 0;
	}

	i = 0;

	while(i < size1){
		bitmap[str1[i]] ++;
		bitmap[str2[i++]] --;
	}

	i = 0;

	while(i < 256){
		if(bitmap[i++]){
			return 0;
		}
	}

	return 1;
}
