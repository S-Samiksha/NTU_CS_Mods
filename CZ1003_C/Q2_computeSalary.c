#include <stdio.h>
void readInput(int *id, int *noOfHours, int *payRate);
double computeSalary1(int noOfHours, int payRate);
void computeSalary2(int noOfHours, int payRate, double *grossPay);
int main()
{
    int id=-1, noOfHours, payRate;
    double grossPay;
    readInput(&id, &noOfHours, &payRate);
    while (id!=-1)
    {
        printf("computeSalary1(): ");
        grossPay = computeSalary1(noOfHours, payRate);
        printf("ID %d grossPay %.2f \n", id, grossPay);
        printf("computeSalary2(): ");
        computeSalary2(noOfHours, payRate, &grossPay);
        printf("ID %d grossPay %.2f \n", id, grossPay);
        readInput(&id, &noOfHours, &payRate);
    }
    return 0;

}
void readInput(int *id, int *noOfHours, int *payRate)
{
    int identification;
    printf("Enter ID (-1 to end): \n");
    scanf("%d", &identification);
    if (identification > 0){
        printf("Enter number of hours: \n");
        scanf("%d", noOfHours);
        printf("Enter hourly pay rate: \n");
        scanf("%d", payRate);
        *id = identification;
    }
    else
        *id = -1; 

        
}
double computeSalary1(int noOfHours, int payRate)
{
    int straighttime=160;
    int overtime=0;
    double Salary;
    if (noOfHours>160){
        overtime = noOfHours - straighttime;
        Salary = straighttime*payRate + overtime*payRate*1.5;
    }
    else
       Salary = noOfHours*payRate; 
    
    return Salary;
}
void computeSalary2(int noOfHours, int payRate, double *grossPay)
{
    int straighttime=160;
    int overtime=0;
    double Salary;
    if (noOfHours>160){
        overtime = noOfHours - straighttime;
        Salary = straighttime*payRate + overtime*payRate*1.5;
    }
    else
       Salary = noOfHours*payRate; 
    
    *grossPay = Salary;
}