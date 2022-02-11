/**
 * circle
 */
//x and y are coordinate points not the radius 

package q2;
import java.util.*;
public class circle extends point{

    private final double PI = 3.14;  
    private double area;
     
    public circle(int radius){
        super(radius, radius);
    }

    public int setRadius(int radius){
        setPoint(radius, radius);
        return 0;
    }

    public int getRadius(){
       return getX();
    }

    public String toString(){
        return toString();
    }

    public double area(){
        area = getX()*getX()*PI;
        return area;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Radius");
        int radius = sc.nextInt();
        circle firstcircle = new circle(radius);
        System.out.println("Area is: " + firstcircle.area());
        sc.close();

    }
}