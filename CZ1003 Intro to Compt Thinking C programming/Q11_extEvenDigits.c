# include <stdio.h> 
# include <math.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *results);
int main()
{
    int number, result = INIT_VALUE;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}

int extEvenDigits1(int num)
{
    int remainder;
    float result1=0;
    int exp=0;
    while (num>0){
        remainder = num%10;
        if (remainder%2 == 0){
            result1 = result1 + (remainder * pow(10, exp));
            exp++;
        }
        num = num/10;    
    }
    if (result1 ==0){
        result1 = -1;
    }
    return result1;
}

void extEvenDigits2(int num, int *result)
{
    int remainder;
    float result1=0;
    int exp=0;
    while (num>0){
        remainder = num%10;
        if (remainder%2 == 0){
            result1 = result1 + (remainder * pow(10, exp));
            exp++;
        }
        num = num/10;    
    }
    if (result1 ==0){
        result1 = -1;
    }
    *result = result1;
}
