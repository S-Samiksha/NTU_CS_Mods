import java.util.Scanner;

public class P3{
    public static void main(String[] args) {
    	System.out.println("First Table: ");
        Scanner var = new Scanner (System.in);
        System.out.println("Enter starting value: ");
        int startingVal = var.nextInt();
        System.out.println("Enter ending value: ");
        int endingVal = var.nextInt();
        System.out.println("Enter increment value: ");
        int incrementVal = var.nextInt();
        var.close();
        int i = 0;
        if (endingVal>startingVal){
            System.out.println("Starting : "+startingVal+ ", ending : " + endingVal+ ", increment: "+ incrementVal);
            System.out.println("US$      S$");
            System.out.println("-----------");
            for (i=startingVal; i<=endingVal; i+=incrementVal){
            System.out.println(i+"        "+i*1.82);
            }
        }
        else{
            System.out.println("Starting : "+startingVal+ ", ending : " + endingVal+ ", increment: "+ incrementVal +" - Error Input");
        }

        i = 0;
        if (endingVal>startingVal){
            System.out.println("Starting : "+startingVal+ ", ending : " + endingVal+ ", increment: "+ incrementVal);
            System.out.println("US$      S$");
            System.out.println("-----------");
            while(i<=endingVal){
                System.out.println(i+"        "+i*1.82);
                i+=incrementVal;
            }
        }
        else{
            System.out.println("Starting : "+startingVal+ ", ending : " + endingVal+ ", increment: "+ incrementVal +" - Error Input");
        }
        
        i = 0;
        if (endingVal>startingVal){
            System.out.println("Starting : "+startingVal+ ", ending : " + endingVal+ ", increment: "+ incrementVal);
            System.out.println("US$      S$");
            System.out.println("-----------");
            do{
                System.out.println(i+"        "+i*1.82);
                i+=incrementVal;
            } while(i<=endingVal);
        }
        else{
            System.out.println("Starting : "+startingVal+ ", ending : " + endingVal+ ", increment: "+ incrementVal +" - Error Input");
        }
        
    }
    
}
