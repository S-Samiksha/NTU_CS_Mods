#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
    int ar[50], i, size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", ar+i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for(i=0;i<size;i++)
        printf("%d ", *(ar+i));
    return 0;
}
void swapMinMax1D(int ar[], int size)
{
    int i=0, min=999, max=-999, maxindex=0, minindex=0;
    int tempvalue;
    for(i=0;i<size; i++){
        if (ar[i]>= max){
            max = ar[i];
            maxindex = i;
        }
        if (min >= ar[i]){
            min = ar[i];
            minindex = i;
        }
    }
    tempvalue = ar[minindex];
    ar[minindex] = ar[maxindex];
    ar[maxindex] = tempvalue;
    
    
}