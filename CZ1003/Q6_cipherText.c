#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main()
{
    char str[80], dummychar, *p;
    int choice;
    printf("Select one of the following options: \n");
    printf("1: cipher() \n");
    printf("2: decipher \n");
    printf("3: exit() \n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                scanf("%c", &dummychar);
                printf("Enter the string: \n");
                fgets(str, 80, stdin);
                if (p=strchr(str, '\n')) *p ='\0';
                printf("To cipher: %s ->", str);
                cipher(str);
                printf("%s\n", str);
                break;
            case 2:
                scanf("%c", &dummychar);
                printf("Enter the string: \n");
                fgets(str, 80, stdin);
                if (p=strchr(str, '\n')) *p = '\0';
                printf("To decipher: %s -> ", str);
                decipher(str);
                printf("%s\n", str);
                break;
            default:
                break;
        }
    }while (choice<3);
    return 0;
}
void cipher(char *s)
{
    int i=0;
    for(i=0; i<strlen(s);i++){
        if(isdigit(s[i])!=0){
            s[i]=s[i];
        }
        else if (s[i]=='Z'){
            s[i] = 'A';
        }
        else if (s[i]=='z'){
            s[i]='a';
        }
        else if((s[i]>='A' && s[i]<'Z') || (s[i]>='a' && s[i]<'z')){
            s[i]=(s[i])+1;
        }
        
    }

}
void decipher(char *s)
{
    int i=0;
    for(i=0; i<strlen(s);i++){
        if(isdigit(s[i])!=0){
            s[i]=s[i];
        }
        else if (s[i]=='A'){
            s[i] = 'Z';
        }
        else if (s[i]=='a'){
            s[i]='z';
        }
        else if((s[i]>'A' && s[i]<='Z') || (s[i]>'a' && s[i]<='z')){
            s[i]=(s[i])-1;
        }
        
    }
}