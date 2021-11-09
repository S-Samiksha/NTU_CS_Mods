#include <stdio.h>
void find2Max1D(int ar[], int size, int *max1, int *max2);
int main()
{
    int max1, max2;
    int ar[10], size, i;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0;i<size;i++)
        scanf("%d", &ar[i]);
    find2Max1D(ar, size, &max1, &max2);
    printf("Max1: %d\nMax2: %d\n", max1, max2);
    return 0;
}
void find2Max1D(int ar[], int size, int *max1, int *max2)
{
    int i=0, tempmax =0;
    *max1 = -999; //here also be careful 
    *max2 = -999;
    for(i=0;i<size;i++)
    {
        if(ar[i] >= (*max1)){
            *max2 = *max1;  //the technique is here 
            *max1 = ar[i];
        }
        if(ar[i]<*max1 && ar[i]>=*max2) // if there is a very small number in the array 
        {
            *max2 = ar[i];
        }
    }

}