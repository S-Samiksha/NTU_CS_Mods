import java.util.Scanner;

public class Shape3DApp implements Shape{

	private static final float PI = (float) 3.14;

	public Shape3DApp() {
		
	}
	
	public float Square(float width) {
		// TODO Auto-generated method stub
		return width*width*6;
	}

	public float Rectangle(float height, float width) {
		// TODO Auto-generated method stub
		return height*width*6;
	}

	@Override
	public float Circle(float radius) {
		// TODO Auto-generated method stub
		return (4*PI*radius*radius);
	}

	@Override
	public float Triangle(float height, float width) {
		// TODO Auto-generated method stub
		return width*width + 2*(height*width);
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int size, choice;
		float height, width, radius, totalVolume=0, depth;
		Shape3DApp object = new Shape3DApp();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of shapes");
		size = sc.nextInt();
		for (int i=0; i<size;i++) {
			System.out.println("Choose the following");
			System.out.println("1: Sqaure");
			System.out.println("2: Rectangle");
			System.out.println("3: Circle");
			System.out.println("4: Triangle");
			choice = sc.nextInt();
			switch(choice) {
				case 1:
					System.out.println("Enter the width of Square: ");
				    width = sc.nextFloat();
				    totalVolume += object.Square(width);
				    break;
				case 2:
					System.out.println("Enter the width of Rectangle: ");
				    width = sc.nextFloat();
				    System.out.println("Enter the height of Rectangle: ");
				    height = sc.nextFloat();
				    totalVolume += object.Rectangle(height, width);
				    break;
				case 3:
					radius = 0;
					System.out.println("Enter the radius of Circle: ");
				    radius = sc.nextFloat();
				    totalVolume += object.Circle(radius);
				    break;
				case 4:
					System.out.println("Enter the width of square of Triangle: ");
				    width = sc.nextFloat();
				    System.out.println("Enter the height of Triangle: ");
				    height = sc.nextFloat();
				    totalVolume += object.Triangle(height, width);
				    break;
			}
		}
		System.out.printf("The total Volume is: %.3f", totalVolume);
		

	}

}
