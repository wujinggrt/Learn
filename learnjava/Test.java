package learnjava;

public class Test
{
	protected void Method()
	{
		System.out.println("This is a method of class Test!");
	}

	private int a = 1;

	public void P()
	{
		System.out.println(this.a);
	}

	public static void main(String[] args)
	{
		Test temp = new Test();
		System.out.println(temp.a);
	}
}

