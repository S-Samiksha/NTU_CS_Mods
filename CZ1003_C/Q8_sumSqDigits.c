#include <stdio.h>
int sumSqDigits1(int num);
void sumSqDigits2(int num, int *result);
int main()
{
    int num, result;

    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("sumSqDigits1(): %d\n", sumSqDigits1(num));
    sumSqDigits2(num, &result);
    printf("sumSqDigits2(): %d\n", result);
    return 0;

}
int sumSqDigits1(int num)
{
    int remainder = 0;
    int result=0;
    while (num>0){
        remainder = num % 10; 
        result = result + remainder*remainder;
        num = num/10;
    }
    return result;
}
void sumSqDigits2(int num, int *result)
{
    int remainder = 0;
    int localresult=0;
    while (num>0){
        remainder = num % 10; 
        localresult = localresult + remainder*remainder;
        num = num/10;
    }
    *result = localresult;

}