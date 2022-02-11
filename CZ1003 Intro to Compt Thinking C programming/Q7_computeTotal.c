#include <stdio.h>
void computeTotal (int numOfLines);
int main(){
    int numOfLines;
    printf("Enter number of lines: \n");
    scanf("%d", &numOfLines);
    computeTotal(numOfLines);
    return 0;
}
void computeTotal(int numOfLines){
   int array_sum[10];
   int j=0, i=0, total=0, numOfValues=0;
   for(j=1;j<=numOfLines;j++){
        printf("Enter line %d: \n", j);
        scanf("%d", &numOfValues);
        for(i=0; i<numOfValues; i++){
            scanf(" %d", &array_sum[i]);
            total = total + array_sum[i];
        }
        printf("Total: %d \n", total);
        total = 0;
        numOfValues = 0;
   } 
}