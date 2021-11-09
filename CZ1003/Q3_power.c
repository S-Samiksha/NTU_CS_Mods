#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
    int power;
    float number, result = -1;

    printf("Enter the number and power: \n");
    scanf("%f %d", &number, &power);
    printf("power1(): %.2f\n", power1(number, power));
    power2(number, power, &result);
    printf("power2(): %.2f", result);
    return 0;
}
float power1(float num, int p)
{
    int i;
    float result = 1.0;
    if (p > 0){
        for(i=0; i<p; i++)
        {
             result = result * num;
        }
    }

    else if (p < 0){
        p = p * -1;
        for(i=0; i<p; i++)
        {
             result = result * num;
        }

        result = 1/result;
    }

    return result;
    

}
void power2(float num, int p, float *result)
{
    float result1 = 1;
    int i;
    if (p > 0){
        for(i=0; i<p; i++)
        {
             result1 = result1 * num;
        }
    }

    else if (p < 0){
        p = p * -1;
        for(i=0; i<p; i++)
        {
             result1 = result1 * num;
        }

        result1 = 1/result1;
    }

    *result = result1;
}
