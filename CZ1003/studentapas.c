#include <stdio.h>
#include <string.h>
struct student{
   char name[20]; /* student name */
   double testScore; /* test score */
   double examScore; /* exam score */
   double total;  /* total = (testScore+examScore)/2 */
};
double average(struct student *s, int size);
int main()
{
   struct student Student[50];
   char *p;
   int i=0;
   int size=0;
   
   printf("Enter student name: \n");
   fgets(Student[i].name, 20, stdin);
   if(p=strchr(Student[i].name, '\n')) *p = '\0';
   while (strcmp(Student[i].name, "END")!=0){
       size++;
       printf("Enter test score: \n");
       scanf("\n");
       scanf("%lf\n", &Student[i].testScore);
       printf("Enter exam score: \n");
       scanf("%lf\n", &Student[i].examScore);
       Student[i].total = (Student[i].testScore + Student[i].examScore)/2.0;
       printf("Student %s total = %.2lf\n", Student[i].name, Student[i].total);
       i++;
       printf("Enter student name: \n");
       fgets(Student[i].name, 20, stdin);
       if(p=strchr(Student[i].name, '\n')) *p = '\0';
   }
   
   printf("average(): %.2f\n", average(Student, size));           
   return 0;
}
double average(struct student *s, int size)
{
    
   double average=0;
   int i=0;
   if (size >0){
       for (i=0; i<size; i++){
           average = average + (*s).total;
           s++;
       }
   }
   else
    size = 1;
   /* Write your program code here */
   average = average/size;
   return average;
}