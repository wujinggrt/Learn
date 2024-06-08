package learnjava.ch05;

import java.util.ArrayList;

public class ObjectAnalyzerTest
{
	public static void main(String[] args)
	{
		ArrayList<Integer> s = new ArrayList<>();
		for(int i = 1; i <= 5; i++)
			s.add( i * i);
		System.out.println(new ObjectAnalyzer().toString(s));
	}
}