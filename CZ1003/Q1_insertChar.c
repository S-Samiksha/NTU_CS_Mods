#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80], b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p=strchr(a, '\n')) *p = '\0';
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a, b, ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
   int len=0, i=0, index=0, count=0;
   len = strlen(str1) + strlen(str1)%3;
   for(i=0; i<strlen(str1);i++){
       str2[index]=str1[i]; // add the first 2=3
       count++;
       index++;
      if (count==3){   //add the ch
          str2[index] = ch;
          index++;      //increase the index
          count=0;
      }
   }
   
}