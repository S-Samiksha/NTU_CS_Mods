/**
 * PlaneSeat
 */
public class PlaneSeat {

    private int seatId;
    private boolean assigned=false; //false is all lowercase 
    private int customerId=-1;

    //is the constructor for the class
    public PlaneSeat(int seat_id){
        seatId = seat_id;
    }

    //a get method that returns the seat number 
    public int getSeatID(){
        return seatId;
    }

    //a get method that returns the customer number
    public int getCustomerID(){
        return customerId;
    }

    //a method that returns a boolean on whether the seat is occupied 
    public boolean isOccupied(){
        return assigned;
    }

    //a method that assigns a seat to a customer
    public void assign(int cust_id){
        customerId = cust_id;
        assigned = true;
    }

    //a method that unassigns a seat
    public void unassign(){
        customerId = 0;
        assigned = false;
    }

}