/**
  *	works with ascii charactor only
  *
**/

# include <stdio.h>

int main(int argc, char* argv[])
{
	if(argc != 2){
		printf("./1_1 your_string\n");
		return 0;
	}

	int comp[256];

	int i = 0;

	for(; i < 256; i++){
		comp[i] = 0;
	}
	int total = 0;
	total = sizeof(argv[1]);
	//char *string = NULL;
	//*string = argv[1];
	
	for(i = 0; i < total; i++ ){
		if( *(comp + argv[1][i]) == 0)
			*(comp + argv[1][i]) += 1 ;
		else
			break;
	}

	if( i == total ){
		printf("YES.\n");
	}else{
		printf("NO.\n");
	}
	return 0;
}
