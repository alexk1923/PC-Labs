#include <stdio.h>
#include <string.h>

void print_all_char_occurences(char c, const char s[])
{
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == c)
            printf("pt %d, c=%c\n", i, c);
}

void print_all_string_occurences(const char *word, const char *phrase)
{
    const char *s = phrase;
    while (s) {           
        s = strstr(s,word);
        if(!s) {
            break;
        }
        printf("%d ", (int)(s - phrase));
        ++s;
    }
    printf("\n");
}

int main(void)
{
    char s[] = "xlm_xlt_xgm_xlm_xxt";
    char c = 'x';
    char word[] = "xlm";
    print_all_char_occurences(c,s);
    print_all_string_occurences(word,s);
    return 0;
}