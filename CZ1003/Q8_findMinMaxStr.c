#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int size);
int main()
{
    char word[SIZE][40];
    char first[40], last[40];
    int i, size;

    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d words: \n", size);
    for (i=0; i<size; i++)
        scanf("%s", word[i]);
    findMinMaxStr(word, first, last, size);
    printf("First word = %s, Last word = %s\n", first, last);
    return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last, int size)
{
    int i=0, min=999, max=-999;
    for(i=0; i<size;i++){
        if(word[i][0]>max){
            max = word[i][0];
            strcpy(last, word[i]);
        }
        if(word[i][0]<min){
            min = word[i][0];
            strcpy(first, word[i]);
        }
        
    }
}