#include <stdio.h>
#include <math.h>
void specialNumbers1D(int ar[], int num, int *size);
int main()
{
    int a[20], i, size=0, num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
        printf("%d ", a[i]);
    return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
    int i=0, j=0, result=0, remainder=0, tempnum=0;
    for(i=100; i<=num; i++){  //num not size 
        tempnum = i;  //tempnum should be outside not inside 
        for(j=0; j<3; j++){
            remainder = tempnum%10;
            result = result + pow(remainder, 3);
            tempnum = tempnum/10;
        }
        if (i == result){
            ar[*size] = result;
            (*size)++; //must change the size because it is what affects the main looop 
        }
        result =0;
    }
    
}