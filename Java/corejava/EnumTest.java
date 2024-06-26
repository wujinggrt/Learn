package learnjava;

import java.util.*;

/**
* This program demonstrates enumerated types.
* @version 2017-11-9.
* @author wujing GRT.
*/
public class EnumTest
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Enter a size:(SMALL, MEDIUM, LARGE, EXTRA_LARGE) ");
		String input = in.next().toUpperCase();
		Size size = Enum.valueOf(Size.class, input);
		System.out.println("Size = " + size );
		System.out.println("abbreviation = " + size.getAbbreviation());
		if(size == Size.EXTRA_LARGE)
			System.out.println("GRT!");
	}
}

enum Size
{
	SMALL("S"), MEDIUM("M"), LARGE("L"), EXTRA_LARGE("XL");

	private Size(String abbreviation)
	{
		this.abbreviation = abbreviation;
	}
	public String getAbbreviation(){ return abbreviation; };

	private String abbreviation;
}