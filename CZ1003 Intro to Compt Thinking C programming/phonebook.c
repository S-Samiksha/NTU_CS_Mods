#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
   char name[20];
   int telno;
} PhoneBk;
void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);
int main() {
   PhoneBk s[MAX];
   char t[20], *p;
   int size=0, choice;
   char dummychar;
     
   printf("Select one of the following options: \n");
   printf("1: readin()\n");      
   printf("2: search()\n");
   printf("3: printPB()\n");
   printf("4: exit()\n");       
    do{
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice){
         case 1:     
            scanf("%c", &dummychar);        
            size=readin(s);  
            break;
         case 2:  
            scanf("%c", &dummychar);   
            printf("Enter search name: \n");
            fgets(t, 20, stdin);   
            if (p=strchr(t,'\n')) *p= '\0';
            search(s,size,t);                    
            break;
         case 3:  
            printPB(s, size);
            break;
          
      } 
    } while (choice< 4);
     return 0; 
    
}
void printPB(PhoneBk *pb, int size)   
{
   int i=0;
   printf("The phonebook list:\n");
   if (size==0){
       printf("Empty phonebook\n");
   }
   else{
       for(i=0;i<size;i++){
           printf("Name: %s\n", pb[i].name);
           printf("Telno: %d\n", pb[i].telno);
       }
   }
    
}
int readin(PhoneBk *pb) 
{
    int size=0, i=0;
    char name[20], *p;
    while(1){  //remember hte while loop condition!!!
        printf("Enter name:\n");
        fgets(name, 20, stdin);
        if (p=strchr(name,'\n')) *p= '\0';
        scanf("\n");
        if (strcmp(name, "#")==0){  //use another variable first if that the case so you dont have to remove later
            break;
        }
        else{
            strcpy(pb[i].name, name);
        }
        printf("Enter telno:\n");
        scanf("%d", &pb[i].telno);
        scanf("\n");
        i++;
        size++; //remember the size
    }
    return size;
    
}
void search(PhoneBk *pb, int size, char *target) 
{
  int i=0, result =0;
  for(i=0;i<size;i++){
      if (strcmp(pb[i].name, target)==0){
            printf("Name: %s, Tel: %d\n", pb[i].name, pb[i].telno); 
            result =1;
        }
      
  }
  if(result==0){
      printf("Name not found!\n");
  }
  
    
}