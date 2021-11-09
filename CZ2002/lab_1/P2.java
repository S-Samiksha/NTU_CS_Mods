
import java.util.Scanner;

public class P2 {

    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);
        System.out.println("Enter salary: ");
        int userSalary = userInput.nextInt();
        System.out.println("Enter merit: ");
        int userMerit = userInput.nextInt();
        if (userSalary>=600 && userSalary<=649 && userMerit >=10){
            System.out.println("salary: $"+userSalary+", merit:"+userMerit+" - Grade B");

        }
        else if (userSalary<=649 && userMerit <=10 ){
            System.out.println("salary: $"+userSalary+", merit:"+userMerit+" - Grade C");
        }
        else if(userMerit<20 && userSalary<749 && userSalary>=700){
            System.out.println("salary: $"+userSalary+", merit:"+userMerit+" - Grade B");
        }
        else if(userSalary>=700 && userMerit>=20){
            System.out.println("salary: $"+userSalary+", merit:"+userMerit+" - Grade A");
        }
        
        else {
            System.out.println("salary: $"+userSalary+", merit:"+userMerit+" - Invalid Grade");
        }
        userInput.close();
    }
}