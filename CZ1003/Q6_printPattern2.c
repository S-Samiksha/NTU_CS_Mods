#include <stdio.h>
void printPattern3(int height);
int main(){
    int height;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("printPattern3(): \n");
    printPattern3(height);
    return 0;
}
void printPattern3(int height)
{
    int i;
    int j;
    int number;
    for(j=1; j<=height; j++)
    {
        for(i=1; i<=j; i++){
            number = i+j-1;
            if (number>10) {number = number - 10;}
            printf("%d", number);
        }
        printf("\n");
    }
}