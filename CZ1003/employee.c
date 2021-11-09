#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
 char name[40];
 char telno[40];
 int id;
 double salary;
} Employee;
void printEmp(Employee *emp, int size);
int readin(Employee *emp);
int search(Employee *emp, int size, char *target);
int addEmployee(Employee *emp, int size, char *target);
int main()
{
    Employee emp[MAX];
    char name[40], *p;
    int size, choice, result;

    printf("Select one of the following options: \n");
    printf("1: readin() \n");
    printf("2: search() \n");
    printf("3: addEmployee() \n");
    printf("4: print() \n");
    printf("5: exit() \n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size = readin(emp);
                break;
            case 2:
                printf("Enter search name: \n");
                scanf("\n");
                fgets(name, 40, stdin);
                if (p=strchr(name,'\n')) *p = '\0';
                result = search(emp,size,name);
                if (result != 1)
                printf ("Name not found! \n");
                break;
            case 3:
                printf("Enter new name: \n");
                scanf("\n");
                fgets(name, 40, stdin);
                if (p=strchr(name,'\n')) *p = '\0';
                    result = search(emp,size,name);
                if (result != 1)
                    size = addEmployee(emp, size, name);
                else
                    printf("The new name has already existed in the database\n");
                break;
            case 4:
                printEmp(emp, size);
                break;
            default:
                break;
        }
    } while (choice < 5);
    return 0;
} 
void printEmp(Employee *emp, int size)
{
    int i;

    printf("The current employee list: \n");
    if (size==0)
        printf("Empty array\n");
    else
    {
        for (i=0; i<size; i++)
            printf("%s %s %d %.2f\n",emp[i].name,emp[i].telno,emp[i].id, emp[i].salary);
    }
}
int readin(Employee *emp)
{
 /* Write your code here */
    int i=0, size=0;
    char *p;
    
   
    while(size<100){    // remember to use the correct variable esp when copying and pasting
        printf("Enter Name: \n");
        scanf("\n");
        fgets(emp[i].name, 40, stdin);
        if (p=strchr(emp[i].name, '\n')) *p='\0';
        if (strcmp(emp[i].name, "#")==0){
            strcpy(emp[i].name, "\0");
            break;
        }
        printf("Enter tel: \n");
        fgets(emp[i].telno, 40, stdin);
        if (p=strchr(emp[i].telno, '\n')) *p='\0';
        printf("Enter id: \n");
        scanf("\n");       //afterwads, this is important!!!!!
        scanf("%d", &emp[i].id);
        printf("Enter salary: \n");
        scanf("%lf", &emp[i].salary);
        i++;
        size++; //remember to increase size if the programme already does not do so
    }
 
    return size;
}
int search(Employee *emp, int size, char *target)
{
    int result=0, i=0;
    for(i=0;i<size;i++){
        if(strcmp(emp[i].name, target)==0){
            result = 1;
            printf("Employee found at index location: %d\n", i); //remember the new lines 
            printf("%s %s %d %.2f\n",emp[i].name,emp[i].telno,emp[i].id, emp[i].salary);
        }
    }
    return result;

}
int addEmployee(Employee *emp, int size, char *target)
{
 /* Write your code here */
    char *p;
    strcpy(emp[size].name, target);
    printf("Enter tel: \n");
    fgets(emp[size].telno, 40, stdin);
    if (p=strchr(emp[size].telno, '\n')) *p='\0';
    printf("Enter id: \n");
    scanf("\n");       //afterwads, this is important!!!!!
    scanf("%d", &emp[size].id);
    printf("Enter salary: \n");
    scanf("%lf", &emp[size].salary);  //the & symbol is needed
    printf("Added at positon: %d\n", size);
    size++;  //same thing here, return the size and increment it as well
    
 return size;
} 