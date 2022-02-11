#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
    int i,b[50],size;
    printf("Enter array size: \n"); 
    scanf("%d", &size);
    printf("Enter %d data: \n", size); 
    for (i=0; i<size; i++)
        scanf("%d",&b[i]);
    printf("platform1D(): %d\n", platform1D(b,size)); 
    return 0;
   }

int platform1D(int ar[], int size)
{
    int i=0, j=0, count=0, result=0;
    for(i=0; i<size; i++){
        for(j=i;j<size; j++){
            if(ar[i]==ar[j]){
                count++;
            }
            else 
                break;
        }
        if (count>result){
            result = count;
        }
        count = 0;
    }
    return result;
}
