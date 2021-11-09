/*
change line 1 and 3: syntax for function 
change the scanf too
how the bubble sort works 
you need n-1 passes of the array since i is equal to 0, it is n-1 
so the i starts from n-2 
name of the file is the same as classes 
change lines: 1, 3, 20, 22, 24, 25, 
must be static element do you can refer to that element 
static will allow you to refer to the method 
in java, arrays are like objects.
you need to define the array type of size 100 
everything you are operating in java is based on objects and classes 
*/
/* how do you improve this?
you dont really need 100 size for array 
you can ask the user so assign the size dynamically

try and except learn later
 */


import java.util.Scanner;
public class q3 {
    public static void bubble(int a[], int n){
        int i, j, t;
        for(i=n-2;i>=0;i--){
            for(j=0;j<=i;j++){
                if(a[j]>a[j+1]){
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        } 

    }
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n,i;
        int a[] = new int[100]; // you need this 
        a = new int[100];
        System.out.println("Enter number of Integer elements to be sorted: ");
        n = in.nextInt();
        for( i=0;i<=n-1;i++){
            System.out.println("Enter integer value for element no.: "+ (i+1)); 
            a[i] = in.nextInt();
        }
        bubble(a, n);

        System.out.print("Finally sorted array is: ");
        for( i=0;i<=n-1;i++){
            System.out.print(a[i]+" "); 
        }
        
        
        
    }

}
