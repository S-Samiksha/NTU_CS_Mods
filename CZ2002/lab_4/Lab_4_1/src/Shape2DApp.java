import java.util.*;

public class Shape2DApp implements Shape{

	private static final float PI = (float) 3.14;
	
	public Shape2DApp() {
		
	}
	
	public float Square(float width) {
		// TODO Auto-generated method stub
		return width*width;
	}


	public float Rectangle(float height, float width) {
		// TODO Auto-generated method stub
		return height*width;
	}

	@Override
	public float Circle(float radius) {
		// TODO Auto-generated method stub
		return PI*radius*radius;
	}

	@Override
	public float Triangle(float height, float width) {
		// TODO Auto-generated method stub
		return (float)0.5*height*width;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int size, choice;
		float height, width, radius, totalArea=0, depth =0;
		Shape2DApp object = new Shape2DApp();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of shapes");
		size = sc.nextInt();
		for (int i=0; i<size;i++) {
			System.out.println("Choose the following");
			System.out.println("1: Square");
			System.out.println("2: Rectangle");
			System.out.println("3: Circle");
			System.out.println("4: Triangle");
			choice = sc.nextInt();
			switch(choice) {
				case 1:
					System.out.println("Enter the width of Square: ");
				    width = sc.nextFloat();
				    totalArea += object.Square(width);
				    break;
				case 2:
					System.out.println("Enter the length of Rectangle: ");
				    width = sc.nextFloat();
				    System.out.println("Enter the breadth of Rectangle: ");
				    height = sc.nextFloat();
				    totalArea += object.Rectangle(height, width);
				    break;
				case 3:
					System.out.println("Enter the radius of Circle: ");
				    radius = sc.nextFloat();
				    totalArea += object.Circle(radius);
				    break;
				case 4:
					System.out.println("Enter the base of Triangle: ");
				    width = sc.nextFloat();
				    System.out.println("Enter the height of Triangle: ");
				    height = sc.nextFloat();
				    totalArea += object.Triangle(height, width);
				    break;
			}
		}
		System.out.printf("The total area is: %.3f", totalArea);
		

	}

}
