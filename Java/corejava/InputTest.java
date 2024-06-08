package learnjava;

import java.util.*;

/** 
* This program demonstrates console input.
* @version 1.0 2017-11-11
* @author Wujing GRT
*/
public class InputTest
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.print("Input the string you want:");
		String line1 = input.nextLine();
		System.out.println("\nYou've pressed strings:" + line1);

		System.out.print("Enter the integer you want:");
		int i1 = input.nextInt();
		System.out.println("\n" + i1);

		System.out.print("Enter words spilted by space:");
		String word;
		while(input.hasNext())
			System.out.print(word + " ");
		System.out.println();
	}
}