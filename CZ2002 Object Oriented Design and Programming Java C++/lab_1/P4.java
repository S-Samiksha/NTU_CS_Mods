
import java.util.Scanner;

public class P4 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Height: ");
        int height = sc.nextInt();
        sc.close();
        String A = "AA";
        String B = "BB";
        int i=0, j=0;
        if (height<=0){
            System.out.println("height = "+height+ " - Error input!!");
        }
        else{
            for(i=0; i<height; i++){
                for(j=0;j<=i;j++){
                    if (j%2 == 0){
                        System.out.print(A);
                    }
                    else{
                        System.out.print(B);
                    }
                }
                System.out.println();
            }
        } 
    }
}