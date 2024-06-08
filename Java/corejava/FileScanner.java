package learnjava;

import java.util.*;
import java.nio.file.Paths;
import java.io.*;
// import java.io.PrintWriiter;

/**
* This program demonstrates a file open action.
* @version 1.0 2017-11-11.
* @author WuJing GRT.
*/
public class FileScanner
{
	public static void main(String[] args)
	{
		Scanner scnTemp = new Scanner(System.in);
		while(System.in.hasNext())
		{
			String s = scnTemp.next();
			System.out.println(s);
		}
	}
}