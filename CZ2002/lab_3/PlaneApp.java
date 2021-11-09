/**
 * PlaneApp
 */

import java.util.*;
public class PlaneApp {
    public static Plane thePlane = new Plane();

    public static void main(String[] args) {
        int c = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("(1) Show the number of empty seats: ");
        System.out.println("(2) Show the list of empty seats: ");
        System.out.println("(3) Show the list of customers together with their seat numbers in the order of seat numbers");
        System.out.println("(4) Show the list of customers together with their seat numbers in the order of the customer ID");
        System.out.println("(5) Assign a customer to a seat");
        System.out.println("(6) Remove a seat assignment");
        System.out.println("(7) Quit");
        do{
            System.out.println();
            System.out.printf("  Enter the number of your choice: ");
            c = sc.nextInt();
            switch(c){
                case 1:
                    thePlane.showNumEmptySeats();
                    break;
                case 2: 
                    thePlane.showEmptySeats();
                    break;
                case 3:
                    System.out.println("The seat assignments are as follow: ");
                    thePlane.showAssignedSeat(true);
                    break;
                case 4:
                    System.out.println("The seat assignments are as follow: "); 
                    thePlane.showAssignedSeat(false);
                    break;
                case 5:
                    System.out.println("Assigning Seat ..");
                    System.out.printf("  Please enter SeatID: ");
                    int seatId = sc.nextInt();
                    System.out.printf("  Please enter Customer ID: ");
                    int cust_id = sc.nextInt();
                    thePlane.assignSeat(seatId, cust_id);
                    break;
                case 6:
                    System.out.printf("  Please enter SeatId: ");
                    seatId = sc.nextInt();
                    thePlane.unAssignSeat(seatId);
                    System.out.println("Seat Unassigned!");
                    break;
                case 7:
                    c = 8;
                    break;
                default:
                    System.out.println("Unrecognizable option! Try again!");
                    c=0;
                    break;
            }

        }while(c<8);
        sc.close();
    }
}