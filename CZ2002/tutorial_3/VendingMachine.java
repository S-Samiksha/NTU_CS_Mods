/**
 * VendingMachine
 */
import java.util.*;
public class VendingMachine {
    private int selectedDrink =0;
    private double totalMoney=0;
    private String choice;
    private Scanner sc1 = new Scanner(System.in);
    public VendingMachine(){
    }
    public double selectDrink(){
        System.out.println("==== Vending Machine ====");
        System.out.println("|1. Buy Beer ($3.00)    |");
        System.out.println("|2. Buy Coke ($1.00)    |");
        System.out.println("|3. Buy Beer ($5.00)    |");
        System.out.println("=========================");
        System.out.println("Please enter selection: ");
        selectedDrink = sc1.nextInt();
        switch(selectedDrink){
            case 1: 
                return 3.00;
            case 2:
                return 1.00;
            case 3:
                return 5.00;
            default:
                return 0.00;
        }
    }
    public double insertCoins(double drinkCost){
        choice = sc1.next();
        //sc1.close();
        switch(choice){
            case "Q":
                drinkCost -= 0.10;
                totalMoney += 0.10;
                break;
            case "T":
                drinkCost -= 0.20;
                totalMoney += 0.20;
                break;
            case "F":
                drinkCost -= 0.50;
                totalMoney += 0.50;
                break;
            case "N":
                drinkCost -= 1.00;
                totalMoney += 1.00;
                break;
            default:
                break;

        }
        System.out.printf("Coins Inserted: %.2f", totalMoney);
        return drinkCost;
    }
    public void checkChange(double amount, double DrinkCost){
        System.out.printf("Change: %.2f \n", (-amount));
    }

    public void printReceipt(){
        System.out.println("Please collect your drink");
        System.out.println("Thank you!");
    }


    public static void main(String[] args) {
        double totalCost=0, change=0;
        VendingMachine vm = new VendingMachine();
        totalCost = vm.selectDrink();
        System.out.println("Please insert coins: ");
        System.out.println("============ Coins Input ============");
        System.out.println("|Enter 'Q' for ten cents input      |");
        System.out.println("|Enter 'T' for twenty cents input   |");
        System.out.println("|Enter 'F' for fifty cents input    |");
        System.out.println("|Enter 'N' for dollar input         |");
        System.out.println("=====================================");
        change = totalCost;
        while (change>0){
            change = vm.insertCoins(change);
            System.out.println();
        }
        vm.checkChange(change, totalCost);
        vm.printReceipt();
    }
}