/**
 * Plane
 */
public class Plane {

    /*seat - instance variable containing information on the seats in the plane. 
    It is declared as an array of 12 seat objects*/
    private static PlaneSeat[] seat = new PlaneSeat[12]; 
    //numEmptySeat - instance variable containing information on the number of empty seats. 
    private static int numEmptySeat; //initialize this to 12 empty seats originally

    //a constructor for the class plane
    public Plane(){
        numEmptySeat = 12;
        for (int i=0; i<12;i++){
            seat[i] = new PlaneSeat(i+1);
        }

    }

    private static PlaneSeat[] sortSeats(){
        //a method to sort the seats according to ascending order of customer ID
        //A copy of the original seat array is used for sorting instead of the original
        PlaneSeat temp;
        PlaneSeat[] copySeat = seat.clone();
        for (int i=0; i<12; i++){
            for(int j=0; j<12-i-1;j++){
                if ((copySeat[j].getCustomerID() > copySeat[j+1].getCustomerID())){
                    temp = copySeat[j];
                    copySeat[j] = copySeat[j+1];
                    copySeat[j+1] = temp;
                }
            }
        }

        return copySeat;

            
    }

    public void showNumEmptySeats(){
        //a method to display the number of empty seats
        System.out.printf("There are %d empty seats \n", numEmptySeat);
    }

    public void showEmptySeats(){
        // a method to display the list of empty seats
        System.out.println("The following seats are empty: ");
        for(int i=0;i<12;i++){
            if (!seat[i].isOccupied()){
                System.out.printf("SeatID %d \n", seat[i].getSeatID());
            }
            
        }
    }

    public void showAssignedSeat(boolean bySeatId){
        // a method to display the assigned seats with seatID and Customer ID
        if (!bySeatId){
            PlaneSeat[] copyseat = new PlaneSeat[12];
            copyseat = sortSeats();
            for(int i=0;i<12;i++){
                if (copyseat[i].isOccupied()){
                    System.out.printf("SeatID %d assigned to CustomerID %d.\n", copyseat[i].getSeatID(), copyseat[i].getCustomerID());
                }
                
            }
        }
        else{
            for(int i=0;i<12;i++){
                if (seat[i].isOccupied()){
                    System.out.printf("SeatID %d assigned to CustomerID %d. \n", seat[i].getSeatID(), seat[i].getCustomerID());
                }
                
            }
        }
        
    }

    public void assignSeat(int seatId, int cust_id){
        if (seat[seatId-1].isOccupied()){
            System.out.println("Seat already assigned to a customer.");
        }
        else{
            seat[seatId-1].assign(cust_id);
            numEmptySeat--;
            System.out.println("Seat Assigned!");
        }
        
    }

    public void unAssignSeat(int seatId){
        //a method that unassigns a seat
        //must find the id 
        seat[seatId-1].unassign();
        numEmptySeat++;
    }


}