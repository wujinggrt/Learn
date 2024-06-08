package learnjava

import java.util.*;

public class ArrayListTest
{
	public static void main(String[] args)
	{
		ArrayList<String> temp = new ArrayList<>();

		temp.add("This is the first string element!");
		temp.add("This is the second string element!");
		temp.add("This is the third string element!");

		for(String e : temp)
			System.out.println(e);
		System.out.println("The size of temp is:" + temp.size());

		temp.set(1, "The second element was reset!");
		System.out.println(temp.get(1));

		temp.remove(1);
		System.out.println("The second element was removed!\nAnd now the ArrayList is underbelow!");
		for(String e : temp)
			System.out.println(e);
	}
}
