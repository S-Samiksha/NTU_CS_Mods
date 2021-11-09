#include <stdio.h>
void printPattern2(int height);
int main()
{
    int height;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("printPattern2(): \n");
    printPattern2(height);
    return 0;
}
void printPattern2(int height)
{
    int i, j;
    for(i=1; i<=height; i++){
        for(j=1; j<=i; j++){
            if ((i+j)%2==0) {printf("A");}
            else printf("B");

        }
        printf("\n");
    }
}