#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NMAX 100

int is_word(const char *s)
{
	while(*s) {
		if(!isalpha(*s)) {
			return 0;
		}
		s++;
	}
	return 1;
}

int count_words(const char *phrase)
{

	int nr_words = 0;

	char *s = strdup(phrase);
	if(!s) {
		printf("strdup() failed");
		return -1;
	}

	char *token = strtok(s, " \n\t.;,?!");

	while(token) {
		
		if(is_word(token)) {
			nr_words++;
			//printf("tkn = %s\n", token);
		}

		token = strtok(NULL, " \n\t.;,?!");

	}

	free(s);

	return nr_words;
}

void print_tokens(const char *phrase)
{
	char *s = strdup(phrase);
	if(!s) {
		fprintf(stderr, "strdup() failed\n");
		return;
	}
	char *token = strtok(s, " \n\t.;,?!");
	while(token) {
		printf("token = %s\n", token);
		token = strtok(NULL, " \n\t.;,?!");
	}
	free(s);
}

int count_occurences(const char *word, const char *phrase)
{	
    char *s = strdup(phrase);
    int count = 0;
	if(!s) {
		fprintf(stderr, "strdup() failed\n");
		return -1;
	}

	char *token = strtok(s, " \n\t.;,?!");
	while(token) {
		if(strcmp(token, word) == 0)
            count++;
		token = strtok(NULL, " \n\t.;,?!");
	}

    free(s);
    return count;
}

int main(void)
{
	char phrase[] = "Gigel is Gigel all the time except when isn't Gigel, but he is still a gigel...";
	char word[] = "Gigel";
    int cnt = count_occurences(word, phrase);

    printf("%d\n", cnt);

	return 0;
}