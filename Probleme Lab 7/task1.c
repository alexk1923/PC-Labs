#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NMAX 100
/*
int is_palindrom(char s[NMAX])
{
	int j = strlen(s)-1;
	ss[j+1]=0;
	for (int i = 0; i < strlen(s) / 2; i++) {
		if(tolower(s[i]) != tolower(s[strlen(s)-1-i]))
			return 0;
	}
	return 1;

}*/


int is_palindrome(char s[NMAX])
{
	int i = 0;
	int j = strlen(s) - 1;

	while(i < j) {

		// if(s[i] == ' ')
		// 	i++;
		// if(s[j] == ' ')
		// 	j--;

		if(tolower(s[i]) != tolower(s[j])){
			printf("s[%d] = %c diferit de s[%d] = %c", i, s[i], j, s[j]);
			return 0;
		}
		
		i++;
		j--;
	}

	return 1;
}


int main(void)
{
	char s[NMAX];
	fgets(s, NMAX, stdin);  // citeste in s un sir de caractere, de la tastatura                                                          
                        	// (cu tot  cu whitespace). Se vor citi maxim NMAX-1 caractere, si nu        
							// exista riscul sa depasim bufferul.
	printf("%s", s);
	s[strlen(s)-1] = 0;
	printf("%d\n", is_palindrome(s));
	
	return 0;
}