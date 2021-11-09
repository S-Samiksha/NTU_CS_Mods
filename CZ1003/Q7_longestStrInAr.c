#include <stdio.h>
#include <string.h>
#define N 20
char *longestStrInAr(char str[N][40], int size, int *length);
int main()
{
    int i, size, length;
    char str[N][40], first[40], last[40], *p, *result;
    char dummychar;

    printf("Enter array size: \n");
    scanf("%d", &size);
    scanf("%c", &dummychar);
    for(i=0;i<size;i++)
    {
        printf("Enter string %d: \n", i+1);
        fgets(str[i], 40, stdin);
        if (p=strchr(str[i], '\n')) *p = '\0';
    }
    result = longestStrInAr(str, size, &length);
    printf("longest: %s \nlength: %d\n", result, length);
    return 0;
}
char *longestStrInAr(char str[N][40], int size, int *length)
{
    int i=0, strlength=0, result=0;
    for(i=0; i<size; i++){
        if(strlen(str[i])>strlength){
            strlength = strlen(str[i]);
            result = i;
        }
    }
    *length = strlength;
    return str[result]; // cannot simply return result??? not too sure why but in case always use this
}