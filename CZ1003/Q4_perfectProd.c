#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);
int main()
{
    int number, result =0;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Calling perfectProd1() \n");
    printf("perfectProd1(): %d\n", perfectProd1(number));

    printf("Calling perfectProd2() \n");
    perfectProd2(number, &result);
    printf("perfectProd2(): %d\n", result);
    return 0;

}
int perfectProd1(int num)
{
    //initializing variables 
    int i, j;
    int sum=0;
    int sumproduct = 1;
    
    //for all values below num 
    for(j=2; j<=num; j++)
    {
        // must find sum of factors 
        for(i=1; i<j; i++){
            if (j%i == 0)
                sum = sum + i;
        }  
        //must see if the sum of factors is equal
        if (j==sum){
            printf("Perfect number: %d \n", j);
            sumproduct = sumproduct * j; 
        }
        sum = 0;
    }
    
    return sumproduct;
}
void perfectProd2(int num, int *prod)
{
    int i, j;
    int sum=0;
    int sumproduct = 1;
    for(j=2; j<=num; j++)
    {
        // must find sum of factors 
        for(i=1; i<j; i++){
            if (j%i == 0)
                sum = sum + i;
        }  
        //must see if the sum of factors is equal
        if (j==sum){
            printf("Perfect number: %d \n", j);
            sumproduct = sumproduct * j; 
        }
        sum = 0;
    }
    
    *prod = sumproduct;

}