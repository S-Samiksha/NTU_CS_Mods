#include <stdio.h>
#include <string.h>
#include <ctype.h> //include it in APAS
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
    char str[50], *p;
    int totVowels=0, totDigits=0, i=0;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p=strchr(str, '\n')) *p='\0';
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
//   int i, j, localVowels=0, localDigits=0;
//   for(i=0; i<=strlen(str); i++)
//   {
//       if (isdigit(*(str+i))>0){
//           localDigits++;}
//       else
//         switch(*(str+i)){
//             case 'a': case 'A': 
//             case 'e': case 'E':
//             case 'i': case 'I':
//             case 'o': case 'O':
//             case 'u': case 'U':
//                 localVowels++;
//                 break;
//             default:
//                 localVowels = localVowels;
//                 break;
//         }
//   }

//   *totDigits = localDigits;
//   *totVowels = localVowels;
    // int i=0;
    // while (*str!='\0'){
    //     if(isupper(*str))
    //         *str=tolower(*str);

    //     if (*str=='a'|| *str=='e'||*str=='i'||*str=='o'||*str=='u')
    //         (*totVowels)= *totVowels + 1;
        
    //     else if (isdigit(*str))
    //         (*totDigits)= *totDigits + 1;
    //     str++; //located here bc u wna str++ regardless of conditions  to check every char
    // }
    int i=0;
    *totVowels = 0;
    *totDigits = 0;
    for (i=0; i<strlen(str); i++){
        if(isupper(str[i])){
            str[i]=tolower(str[i]);
        }

        if (str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            (*totVowels)++;
        }
        
        else if (isdigit(str[i])){
            *(totDigits) = *totDigits + 1; 
        }
    }
    
}
