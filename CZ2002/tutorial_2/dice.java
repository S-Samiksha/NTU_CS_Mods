/**
 * dice
 */
import java.util.*;

public class dice {
    private int valueOfDice =0;
    private static int totalNumber =0;

    public dice(){
        valueOfDice =0;
    }
    public void setDiceValue(){
        Random rand = new Random();
        valueOfDice = rand.nextInt(7);
        totalNumber += valueOfDice;
    }

    public int getDiceValue(){
        return valueOfDice;
    }
    
    public void printDiceValue(){
        System.out.printf("Current Value is %d \n", valueOfDice);
        if (totalNumber > 0){
            System.out.printf("Total Value is %d \n", totalNumber);
        }
    }

    public static void main(String[] args) {
        dice myDice = new dice();
        int c=1;
        Scanner sc = new Scanner(System.in);
        System.out.println("Press 1 to roll dice and press 0 to exit");
        c = sc.nextInt();
        while (c==1){
            myDice.setDiceValue();
            myDice.printDiceValue();
            System.out.println("Press 1 to roll dice and press 0 to exit");
            c = sc.nextInt();
        }
        sc.close();

        
    }
}