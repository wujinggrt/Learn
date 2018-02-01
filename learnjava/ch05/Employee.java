package learnjava.ch05;

import java.time.*;
import java.util.Objects;
/** 
* This demonstrates class Employee.
* @version 1.0 2017-11-13
* @author WuJing GRT
*/
class Employee
{
	private String name;
	private double salary;
	private LocalDate hireDay;

	public Employee(String name, double salary, int year, int month, int day)
	{
		this.name = name;
		this.salary = salary;
		hireDay = LocalDate.of(year, month, day);
	}

	public String getName() { return this.name; }

	public double getSalary() { return salary; }

	public LocalDate getHireDay() { return hireDay; }

	public void raiseSalary(double byPercent) 
	{
		double raise = salary * byPercent / 100;
		salary += raise;
	}

	@Override 
	public boolean equals(Object otherObj)
	{
		if(this == otherObj) return true;

		if(otherObj == null) return false;

		//compare so that ensure both of them are the same class.
		if(getClass() != otherObj.getClass()) return false;

		//if all of subclass has the unit syntax, we can use 
		// if(!(otherObj instanceof Employee)) return false;

		Employee other = (Employee) otherObj;
		return Objects.equals(name, other.getName())
			&& salary == other.getSalary()
			&& Objects.equals(hireDay, other.getHireDay());
	}

	@Override
	public int hashCode()
	{
		return Objects.hash(name, salary, hireDay);
	}
}