import java.util.Scanner;

public class Strings {
	public static void main (String[] args)
	{
		Comparable[] intList;
		int size;
		Scanner scan = new Scanner(System.in);
		System.out.print ("\nHow many characters do you want to sort? ");
		size = scan.nextInt();
		intList = new Comparable[size];
		System.out.println ("\nEnter the String...");
		for (int i = 0; i <size; i++)
			intList[i] = scan.next();
			Sorting.insertionSort(intList);
			System.out.println ("\nYour String in sorted order...");
		//intList[size] = '\0';
		for (int i = 0; i < size; i++)
			System.out.print(intList[i] + " ");
		System.out.println ();
		
		
		}
	
}
