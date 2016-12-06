#include <stdio.h> 
#include <stdlib.h> 

#define SIZE 256

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char buffer[SIZE]; 
	
	if(argc != 3)
	{
		fprintf(stderr, "형식에 맞지 않습니다. 파일이름1 파일이름2를 넣어주세요\n"); 
		exit(1); 
	}

	if( (fp1 = fopen(argv[1], "r")) == NULL || (fp2 = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "파일을 정상적으로 불러올 수 없습니다. \n"); 
		exit(1);
	}

	while( fgets(buffer, SIZE, fp1) != NULL)
		fputs(buffer, fp2); 

	return 0; 
} 
