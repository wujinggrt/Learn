package learnjava;

import java.util.*;

/**  
* This program demonstrates object construction.
* @version 1.0 2017-11-13
* @author WuJing GRT
*/
public class ConstructorTest
{

}

class Employee
{
	private static int nextId;
	private int id;
	private String name;
	private double salary;

	static
	{
		System.out.println("Now is calling static initializer block!");
		Random generator = new Random();
		nextId = generator.nextInt(10000);
	}

	{
		System.out.println("Now is call common initializer block!");
		id = nextId++;
	}

	//three overloaded constructors
	public Employee(String name, double salary)
	{
		this.name = name;
		this.salary = salary;
	}

	public Employee(double salary) { this("Employee #", salary); }

	public Employee() {}

	public String getName() { return this.name; }

	public double getSalary() { return this.salary; }

	public int getId() { return this.id; }

	public static void main(String[] args)
	{
		Employee e = new Employee("Harry", 50000);
		Employee e1 = new Employee(40000);

		System.out.println(e.getName() + "'s Id:" + e.getId() + e.getSalary());
		System.out.println(e1.getName() + "'s Id:" + e1.getId() + e1.getSalary());
	}
}