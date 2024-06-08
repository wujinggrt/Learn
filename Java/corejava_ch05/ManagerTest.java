package learnjava.ch05;

/** 
* This program demonstrates inheritance through Employee and Manager.
* @version 1.0 2017-11-13
* @author WuJing GRT
*/
public class ManagerTest
{
	public static void main(String[] args)
	{
		Manager m = new Manager("Carl Cracker", 80000, 2011, 11, 11);
		m.setBonus(5000);
		Employee[] staff = new Employee[3];

		staff[0] = m;
		staff[1] = new Employee("Harry Hacker", 50000, 2012, 11, 11);
		staff[2] = new Employee("Tony", 40000, 2012, 11, 11);

		for(Employee e : staff)
			System.out.println(e.getName() + ":\nSalary:" + e.getSalary());

		Employee t1 = new Employee("A", 10000, 2011, 11, 11);
		Manager m1 = new Manager("A", 10000, 2011, 11, 11);
		boolean b = t1.equals(m1);
		System.out.println(b);
		System.out.println(m1.getNameOfClass());
		System.out.println(m1.toString());
	}
}