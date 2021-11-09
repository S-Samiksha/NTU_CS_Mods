#include <stdio.h>
int allEvenDigits1(int num);
void allEvenDigits2(int num, int *result);
int main(){
    int number, p=999, result=999;
    printf("Enter a number: \n");
    scanf("%d", &number);
    p = allEvenDigits1(number);
    if (p==1)
        printf("allEvenDigits1(): yes\n");
    else if (p == 0)
        printf("allEvenDigits1(): no\n");
    else 
        printf("allEvenDigits1(): error\n");
    allEvenDigits2(number, &result);
    if (result == 1)
        printf("allEvenDigits2(): yes\n");
    else if (result == 0)
        printf("allEvenDigits2(): no\n");
    else 
        printf("allEvenDigits2(): error\n");
}
int allEvenDigits1(int num)
{
    int result=0, count=0, remainder = 0;
    while (num>0){
        remainder = num%10;
        if (remainder%2 == 0){
            result++;
        }
        count++;
        num = num/10;
    }
    if (result == count){
        result = 1;
    }
    else 
        result = 0;

    return result;
}
void allEvenDigits2(int num, int *result)
{
    int result1=0, count=0, remainder = 0;
    while (num>0){
        remainder = num%10;
        if (remainder%2 == 0){
            result1++;
        }
        count++;
        num = num/10;
    }
    if (result1 == count){
        result1 = 1;
    }
    else 
        result1 = 0;

    *result = result1;

}