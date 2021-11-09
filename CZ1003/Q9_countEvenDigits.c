#include <stdio.h>
int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
    int number, result;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countEvenDigits1(): %d\n", countEvenDigits1(number));
    countEvenDigits2(number, &result);
    printf("countEvenDigits2(): %d\n", result);
    return 0;

}
int countEvenDigits1(int number)
{
    int result=0;
    int remainder = 0;
    while (number>0)
    {   
        remainder = number % 10;
        if (remainder%2 == 0){
            result++;
        }
        number = number/10;

    }
    return result;
}
void countEvenDigits2(int number, int *count)
{
    int result=0;
    int remainder = 0;
    while (number>0)
    {   
        remainder = number % 10;
        if (remainder%2 == 0){
            result++;
        }
        number = number/10;

    }
    *count = result;
}
