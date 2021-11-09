#include <stdio.h>
#include <string.h>
#define INIT_VALUE 999
int findSubstring(char *str, char *substr);
int main()
{
    char str[40], substr[40], *p;
    int result = INIT_VALUE;

    printf("Enter the string \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n')) *p ='\0';
    printf("Enter the substring: \n");
    fgets(substr, 80, stdin);
    if (p = strchr(substr, '\n')) *p ='\0';
    result = findSubstring(str, substr);
    if (result == 1)
        printf("findSubstring(): Is a substring\n");
    else if (result == 0)
        printf("findSubstring(): Not a substring\n");
    else 
        printf("findSubstring(): An error\n");
    
    return 0;
}
int findSubstring(char *str, char *substr)
{
    char *ptr;
    int i=0, j=0, k=0, count=0, result=0;
    for(i=0;i<strlen(str);i++){
        if (str[i]==substr[0]){
            for(j=0; j<strlen(substr); j++){ // very important step here!!!! 
                if (str[i+j]==substr[k]){
                    count++;
                }
                k++;
            }
        }
        else {
            continue;
        }
        if(count==strlen(substr)){
            result= 1;
            break;
        }
    }
    return result;
    
}