package learnjava;

import java.time.*;

/**
* This program is writen to show calendar.
* @version 1.0 2017-11-11.z
* @author WuJing GRT
*/
public class Calendar
{
	private LocalDate date;
	private int year;
	private int month;
	private int today;
	private int weekValue;

	/**
	* This constructor defaultly construct a now LocalDate Object.
	*/
	public Calendar()
	{
		this.date = LocalDate.now();
		this.year = date.getYear();
		this.month = date.getMonthValue();
		this.today = date.getDayOfMonth();
		DayOfWeek week = date.getDayOfWeek();
		this.weekValue = week.getValue();
	}

	/**
	* This constructor create a date you want by inputing date.
	* @param year int year is the year you want
	* @param month int monthis the month you want
	* @param daya int day
	*/
	public Calendar(int year, int month, int day)
	{
		date = LocalDate.of(year, month, day);
		year = date.getYear();
		month = date.getMonthValue();
		today = date.getDayOfMonth();
		DayOfWeek week = date.getDayOfWeek();
		weekValue = week.getValue();
	}

	/**
	* This method print the calendar of this month,
	* and today would be marked with "*".
	*/
	public void printMonth()
	{
		int day;

		System.out.println("Mon Tue Wed Thu Fri Sat Sun");
		
		this.date = this.date.minusDays(today - 1);
		day = this.date.getDayOfMonth();
		DayOfWeek week = this.date.getDayOfWeek();
		this.weekValue = week.getValue();
		//adjust the first day of month position.
		for(int i = 0; i < weekValue - 1; i++)
			System.out.print("    ");

		while(date.getMonthValue() == this.month)
		{
			if(day == this.today)
				System.out.printf("<%2d>", day);
			else
				System.out.printf("%3d ", day);
			//print date in a new line if next week.
			if(date.getDayOfWeek().getValue() == 7)
				System.out.println();

			date = date.plusDays(1);
			day = date.getDayOfMonth();
		}
		if(date.getDayOfWeek().getValue() != 1) System.out.println();
	}

	public static void main(String[] args)
	{
		Calendar temp = new Calendar();
		temp.printMonth();
	}
}