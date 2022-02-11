#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int A[], int low, int high);
int partition (int A[], int low, int high);

void dualSortedSearch (int[],int, int, int[]);

int main()
{
    int i,size,K;
    int* A;
    int index[2] = {-1,-1};

    //Search key
    scanf("%d",&K);

    //create an array
    scanf("%d",&size);
    A=(int *)malloc(sizeof(int)*size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&A[i]);
    }

    quickSort(A,0,size-1);
    time_t now = time(0);
    
    dualSortedSearch(A,size,K,index);
    time_t now2 = time(0);
    printf("%f \n", now-now2);

    if(index[0]!=-1)
        printf("%d %d\n",index[0], index[1]);
    else
        printf("Not found");

    free(A);
    return 0;
}

void dualSortedSearch(int A[], int size, int K, int dualIndex[])
{
   // Write your code here
   // 3 4 5 6 7 8 
   // i want 14 
   //i will add the first and the last if it is lower than K, move first pointer upward
   //if it is higher, move the last pointer downward
   int *front, *end, i=0;
   front = A;
   end = &(A[size-1]);
   while(1){
       if (*front + *end > K){
           end--;
       } else if (*front + *end < K){
           front++;
       }else{
           dualIndex[0] = *front;
           dualIndex[1] = *end;
           return;
       }
   }
}

int partition (int A[], int low, int high)
{
    int pivot = A[high];
    int i = (low - 1);

    int temp;
    for (int j = low; j <= high- 1; j++)
    {
        if (A[j] < pivot)
        {
            i++;

            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i+1];
    A[i+1]= A[high];
    A[high] = temp;
    return (i + 1);
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);

        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}
