#include <stdio.h>
#include <math.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
    int  num, result = 999;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));
    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);
    return 0;
}
int reverseDigits1(int num) //10 lines
{
    int result = 0, count = 0, i = 0, tempnum=num;
    while (tempnum>0){
        tempnum = tempnum/10;
        count++;        
    }
    for(i=0;i<count;i++){
        result = result + (num%10)*pow(10, (count-i));
        num = num/10;
    }
    result = result/10;
    return result;
}
void reverseDigits2(int num, int *result) //much faster way to do it, only 8 lines, one loop 
{
    int result1 = 0, remainder = 0;
    while (num != 0)
    {   
        remainder = num%10;
        result1 = result1*10 + remainder;
        num = num/10;

    }
    *result = result1;
}