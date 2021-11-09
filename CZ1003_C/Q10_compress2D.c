#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;

    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for(j=0; j<colSize;j++)
            scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    int i=0, j=0;
    int countOne=0;
    int processedData = data[0][0];
    for (i=0; i<rowSize; i++)
    {
        processedData = data[i][0]; // assigning the number to another variable
        for(j=0; j<colSize;j++)
        {
            if (data[i][j]==processedData) //checking whether it is the same
            {
                countOne++;
            }
            else
            {
                printf("%d %d ", processedData, countOne); //once it is no longer the same, it will pass the new number to the variable again
                processedData = data[i][j]; //print out the number 
                countOne = 1;
            }
        }
        printf("%d %d", processedData, countOne);
        printf("\n");
        countOne = 0; 
    }
}
//go into each row first
//go into each column 
//while it is still 1, the count increases 
//if not break the loop 
//