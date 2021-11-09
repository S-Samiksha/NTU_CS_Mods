#include <stdio.h>
#include <string.h>
int countWords(char *s);
int main()
{
    char str[50], *p;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str, '\n')) *p = '\0';
    printf("countWords(): %d", countWords(str));
    return 0;
}
int countWords(char *s)
{
    int i=0, count=0, noOfwords=0;
    while(i<strlen(s)){
        if(s[i]==' ' || ispunct(s[i])!=0){
            noOfwords++;
        }
        i++;
    }
    if(i==strlen(s) && noOfwords ==0){
         noOfwords = 1;   
        }
    return noOfwords;
}