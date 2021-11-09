#include <stdio.h> 
double computePay1(int noOfHours, int payRate);
void computePay2(int noOfHours, int payRate, double *grossPay);
int main()
{
    int noOfHours, payRate;
    double grossPay;

    printf("Enter number of hours: \n");
    scanf("%d", &noOfHours);
    printf("Enter hourly pay rate: \n");
    scanf("%d", &payRate);
    printf("computPay1(): %.2f\n", computePay1(noOfHours, payRate));
    computePay2(noOfHours, payRate, &grossPay);
    printf("computPay2(): %.2f\n", grossPay);
    return 0;
}
double computePay1(int noOfHours, int payRate)
{
    int straighttime=160;
    int overtime=0;
    if (noOfHours>160){
        overtime = noOfHours - straighttime;
        payRate = straighttime*payRate + overtime*payRate*1.5;
    }
    else
       payRate = noOfHours*payRate; 
    
    return payRate;

}
void computePay2(int noOfHours, int payRate, double *grossPay)
{
    int straighttime=160;
    int overtime=0;
    if (noOfHours>160){
        overtime = noOfHours - straighttime;
        payRate = straighttime*payRate + overtime*payRate*1.5;
    }
    else
       payRate = noOfHours*payRate;
    
    *grossPay = payRate;

}