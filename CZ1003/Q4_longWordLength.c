#include <stdio.h> 
#include <string.h>
#include <ctype.h> //include in APAS
int longWordLength(char *s);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str, '\n')) *p = '\0';
    printf("longWordLength(): %d", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
    int wordLength=0;
    int max=0;
    int i=0;
    while (i<strlen(s)){  //using a while loop
        while (*(s+i) != ' ' && i<strlen(s) && ispunct(*(s+i))==0){
            wordLength++;
            i++;
        }

        if (wordLength > max){
            max = wordLength;
        }
        wordLength = 0;
        i++;
    }
    
    
    return max;
}