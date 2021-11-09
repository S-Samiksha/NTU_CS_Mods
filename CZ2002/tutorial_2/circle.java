/**
 * circle
 */
import java.util.*;
public class circle {
    private double radius =0, Area = 0, Circumference =0;
    private static final double PI = 3.142;
    public circle(double Radius){
        if (Radius < 0){
            radius = 0;
        }else{
            radius = Radius;
        }

    }
    public void setRadius(double Radius){
        if (Radius < 0){
            radius = 0;
        }else{
            radius = Radius;
        }

    }

    public double getRadius(){
        System.out.println("Radius: " + radius);
        return radius;
    }

    public double area(){
        Area = PI*radius*radius;
        return Area;
    }

    public double circumference(){
        Circumference = 2.0*PI*radius;
        return Circumference;
    }

    public void printArea(){
        area();
        System.out.printf("Area: %.2f \n", Area);
    }

    public void printCircumference(){
        System.out.printf("circumference: %.2f \n", circumference());
    }



    public static void main(String[] args) {
        int c = 0;
        double Radius =0;
        System.out.println("==== Circle Computation ====");
        System.out.println("|1.  Create a new circle   |");
        System.out.println("|2.  Print Area            |");
        System.out.println("|3.  Print circumference   |");
        System.out.println("|4.  Quit                  |");
        Scanner sc = new Scanner(System.in);
        circle myCircle = new circle(0);
        do{
            System.out.println("Choose option(1-3):");
            c = sc.nextInt();
            switch(c){
                case 1: 
                    System.out.println("Enter radius: ");
                    Radius = sc.nextDouble();
                    myCircle.setRadius(Radius);
                    System.out.println("A new circle is created.");
                    break;
                case 2:
                    System.out.println("Area of circle");
                    myCircle.getRadius();
                    myCircle.printArea();
                    break;
                case 3:
                    System.out.println("Circumference of circle");
                    System.out.printf("Radius: %.2f\n", myCircle.getRadius());
                    myCircle.printCircumference();
                    break;
                default:
                    c=5;
                    break;
            }

        } while(c<4);
        sc.close();
    }
}