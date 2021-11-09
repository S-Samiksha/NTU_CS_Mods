#include <stdio.h> 
#include <string.h> 
struct account {
    struct
    {
        char lastName[10];
        char firstName[10];
    } names;
    int accountNum;
    double balance;
};
void nextCustomer(struct account *acct);
void printCustomer(struct account acct);
int main()
{
    struct account record; 
    int flag = 0;
    do {
        nextCustomer(&record);
        if ((strcmp(record.names.firstName, "End") == 0) &&
            (strcmp(record.names.lastName, "Customer") == 0)) 
            flag = 1;
        if (flag != 1) 
            printCustomer(record);
    } while (flag != 1); 
}
void nextCustomer(struct account *acct)
{
    char *p;
    printf("Enter names (firstName lastName): \n");
    scanf("%s %s\n", &(*acct).names.firstName, &(*acct).names.lastName); //need both & and *
    if ((strcmp((*acct).names.firstName, "End") == 0) && (strcmp((*acct).names.lastName, "Customer") == 0)){
                strcpy((*acct).names.firstName, "End"); //remember the *
                strcpy((*acct).names.lastName, "Customer");
            }
    else{
        printf("Enter account number: \n");
        scanf("%d\n", &(*acct).accountNum);
        printf("Enter balance: \n");
        scanf("%lf\n", &(*acct).balance);
    }
}
void  printCustomer(struct account acct)
{
   printf("Customer record: \n");
   printf("%s %s %d %.2lf\n", acct.names.firstName, acct.names.lastName, acct.accountNum, acct.balance);
}