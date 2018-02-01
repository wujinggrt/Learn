package learnjava.ch05;

public class Manager extends Employee
{
	private double bonus;

	public Manager(String name, double salary, int year, int month, int day)
	{
		super(name, salary, year, month, day);
		bonus = 0;
	}

	@Override
	public double getSalary() 
	{
		double baseSalary = super.getSalary();
		return baseSalary + bonus;
	}

	public void setBonus(double bonus) { this.bonus = bonus; }

	public String getNameOfClass()
	{
		return getClass().getName();
	}

	@Override
	public int hashCode()
	{
		return super.hashCode() + 17 * Double.hashCode(bonus);
	}
}