
public class SalePerson implements Comparable<SalePerson> {
	private String firstName;
	private String lastName;
	private int totalSales;
	
	public SalePerson(String firstName, String lastName, int totalSales) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.totalSales = totalSales;
	}
	
	public String toString() {
		return this.lastName + " , " + this.firstName + " : " + totalSales;
	}
	public boolean equals(SalePerson o) {
		return firstName.equals(o.firstName) && lastName.equals(o.lastName);
	}
	public int compareTo(SalePerson o) {
		if (this.totalSales < o.totalSales) {
			return -1;
		} else if (this.totalSales > o.totalSales)  {
			return 1;
		}else if (this.lastName.charAt(0) < o.lastName.charAt(0)){
			return 1;
		}else if (this.firstName.charAt(0) < o.firstName.charAt(0)){
			return 1;
		}else {
			return 0;
		}
	}
	public String getFirstName() {
		return this.firstName;
	}
	public String getLastName() {
		return this.lastName;
	}
	public int getTotalSales() {
		return this.totalSales;
	}
	
	
}
