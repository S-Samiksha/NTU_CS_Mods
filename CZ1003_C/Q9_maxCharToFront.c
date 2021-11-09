#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str, '\n')) *p ='\0';
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    int i=0, maxASCII=-999, result =0, j=0, count=0; //important steps take note!!!
    char sresult[80];
    for(i=0; i<strlen(str); i++){
        if(str[i]>maxASCII){
            maxASCII = str[i];
            result = i;
        }
    }
    sresult[0]=str[result];
    for(i=1;i<strlen(str);i++){
        if(result==0){
            strcpy(sresult, str);
            break;
        }
        if(j!=result){
            sresult[i]=str[j];
            count++;
            j++;
        }
        else if (j=result){
            j++;
            sresult[i]=str[j];
            j++;
        }
    }
    strcpy(str, sresult);
    
} 