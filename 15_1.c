#include <stdio.h>
#include <string.h> 

void changeChar(char *str, char *ptr); 

int main()
{
	char str[512]; 
	
	strcpy(str, "Hello, World"); 
	changeChar(str, "even"); 
	
	strcpy(str, "Hello, World"); 
	changeChar(str, "odd");

	return 0;
} 

void changeChar(char *str, char *ptr)
{
	int i = 0; 

	if( !strcmp(ptr, "even") ) 
	{
		for(i = 0; i < 512; i++) 
			if( str[i] != '\0' )	
				if( i%2 == 0 ) 
					str[i] = 'X'; 
	}


	else if( !strcmp(ptr, "odd") ) 
	{
		for(i = 0; i < 512; i++) 
			if( str[i] != '\0' )	
				if( i%2 == 1 ) 
					str[i] = 'X'; 
	}

	printf("%s \n\n", str);
}
