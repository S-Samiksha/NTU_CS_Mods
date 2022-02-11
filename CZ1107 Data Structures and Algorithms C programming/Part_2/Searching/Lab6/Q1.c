#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dualSearch (int[],int, int, int[]);

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

    time_t now = time(0);
    dualSearch(A,size,K,index);
    time_t now2 = time(0);
    printf("%f \n", (now-now2)*10^100);


    if(index[0]!=-1)
        printf("%d %d\n",index[0], index[1]);
    else
        printf("Not found");

    free(A);
    return 0;
}

void dualSearch(int A[], int size, int K, int dualIndex[])
{
   // Write your code here
   int i=0, j=0;
   for (i=0;i<size;i++){
       for(j=i;j<size;j++){
           if (A[i]+A[j]==K){
               dualIndex[0]=A[i];
               dualIndex[1]=A[j];
               return;
           }
       }
   }

}