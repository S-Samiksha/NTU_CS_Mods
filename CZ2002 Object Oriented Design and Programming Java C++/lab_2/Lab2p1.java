import java.util.*;
public class Lab2p1{
    private static int x=0, y=0, count=0, result=0;
    private static long Result =0;
    private static Scanner sc1 = new Scanner(System.in);
    public static void mulTest(){
        count = 0;
        Random rand = new Random();
        for(int i=0; i<5; i++){
            x = rand.nextInt(11); //need the static key word. why tho?
            y = rand.nextInt(11);
            System.out.printf("How much is %d times %d? ", x, y);
            result = sc1.nextInt();
            if (x*y == result){
                count++;
            }
        }
        System.out.printf("%d answers out of 5 are correct. \n", count);


    }
    public static int divide(int m, int n){
        count = 0;
        if (m < n){
            return 0;
        } else {
            while(m >= n){
                System.out.println("hello");
                m = m - n;
                count++;
            }
            return count;

        }
    }
    public static int modulus(int m, int n){
        if (m < n){
            return m;
        } else {
            while(m >= n){
                m = m - n;
            }
            return m;

        }
    }
    public static int countDigits(int n){
        count = 0;
        while(n>0){
            n = n/10;
            count++;
        }
        return count;
    }
    public static int position(int n, int digit){
        count = -1;
        while(n>0){
            count++;
            if (n%10 == digit){
                count++;
                return count;
            }
            n = n/10;
        }
        count = -1;
        return count;
        
    }
    public static long extractOddDigits(long n){
        Result = 0;
        count = 1;
        while(n>0){
            if ((n%10)%2 == 1){
                Result += (n%10)*count;
                count *= 10;
            }
            n = n/10;
        }
        return Result;
        
    }

    public static void main(String[] args) {
        int choice, m, n, result;
        Long Result = 0L;
        Scanner sc = new Scanner(System.in);
        do {
        System.out.println("Perform the following methods");
        System.out.println("1: multiplication test");
        System.out.println("2: quotient using division by substraction");
        System.out.println("3: remainder using divison by substraction");
        System.out.println("4: count the number of digits");
        System.out.println("5: position of a digit");
        System.out.println("6: extract all odd digits");
        System.out.println("7: quit");
        choice = sc.nextInt();
        switch (choice) {
            case 1: /* add mulTest() call */
                Lab2p1.mulTest();
                break;
            case 2: /* add divide() call */
                result =0;
                System.out.println("Input m: ");
                m = sc.nextInt();
                System.out.println("Input n: ");
                n = sc.nextInt();
                result = Lab2p1.divide(m, n);
                System.out.printf("%d / %d = %d \n", m, n, result);
                break;
            case 3: /* add modulus() call */
                result =0;
                System.out.println("Input m: ");
                m = sc.nextInt();
                System.out.println("Input n: ");
                n = sc.nextInt();
                result = Lab2p1.modulus(m, n);
                System.out.println(m + " % " + n + " = " + result);
                break;
            case 4: /* add countDigits() call */
                result =0;
                System.out.println("Input n: ");
                n = sc.nextInt();
                System.out.printf("n: %d -", n);
                if (n > 0){
                    result = Lab2p1.countDigits(n);
                    System.out.printf("count = %d \n", result);
                }else{
                    System.out.println(" Error input!!"); 
                }
                
                break;
            case 5: /* add position() call */
                result =0;
                System.out.println("n: ");
                n = sc.nextInt();
                System.out.println("Digit: ");
                int digit = sc.nextInt();
                result = Lab2p1.position(n, digit);
                System.out.printf("position = %d \n", result); 
                break;
            case 6: /* add extractOddDigits() call */
                result =0;
                System.out.println("n: ");
                long N = sc.nextInt();
                Result = Lab2p1.extractOddDigits(N);
                System.out.printf("oddDigits = ", Result);
                if (N > 0 && Result != 0){
                    System.out.printf("%d; \n", Result);
                }else if (N>0 && Result == 0){
                    System.out.println("-1"); 
                }else{
                    System.out.println(" Error input!!"); 
                }
                break; 
            case 7: 
                System.out.println("Prorgram terminating ....");
        }
        } while (choice < 7);
    }
}