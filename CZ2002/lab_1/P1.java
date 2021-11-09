
import java.util.Scanner;

public class P1 {

    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);
        System.out.println("Enter Character: ");
        String userCharacter = userInput.nextLine();
        //System.out.println("The entered character is: " + userCharacter);
        switch(userCharacter){
            case "a","A":
                System.out.println("'a','A' - Action movie fan");
                break;
            case "c","C":
                System.out.println("'c', 'C' - Comedy movie fan");
                break;
            case "d","D":
                System.out.println("'d', 'D' - Drama movie fan");
                break;
            default:
                System.out.println("Invalid choice");
                break;
        };
        userInput.close();

    }
}