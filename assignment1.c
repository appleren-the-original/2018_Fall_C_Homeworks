/*
	Alp Eren Gençoğlu 150170019
	BLG 102E Assignment1 19.03.2018
	
	This program determines which weekday the given date corresponds to 
	and how many times the given day-and-month falls on the same weekday 
	starting with the next year and ending on a given year.
*/

#include <stdio.h> // printf & scanf
#include <stdlib.h> // EXIT_SUCCESS

int main()
{
	int year,month,day; // for user's date input.
	int endyear; // for user's endyear input.
	int j,k; // j:zero based century of the year	k:year offset within the century
	int weekday; // to determine which weekday the given date corresponds to.
	
	printf("Enter date [year month day]: ");
	scanf("%d%d%d",&year,&month,&day);
	int realyear=year;  // We will need the original year input but the year will 
                        // be decraased by one if month is 1 or 2, so original value of year must be stored.
						
	switch(month) // Checks invalid dates and prints "Invalid date." to the screen.
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day>31 || day<1)
			{
				printf("Invalid date.\n");
				return EXIT_FAILURE;
			}
			else break;
		case 2:
			if(day>28 || day<1)
			{
				printf("Invalid date.\n");
				return EXIT_FAILURE;
			}
			else break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day>30 || day<1)
			{
				printf("Invalid date.\n");
				return EXIT_FAILURE;
			}
			else break;
		default:
			printf("Invalid date.\n");
			return EXIT_FAILURE;
	}
	
	printf("Enter end year: ");
	scanf("%d",&endyear);
	
	if(month==1 || month==2)
	{
		month+=12;
		year--;
	}
	j = year/100;
	k = year%100;
	
	weekday = (day + 13*(month+1)/5 + k + k/4 + j/4 + 5*j)%7; // Numeric value of the determined weekday.
	
	switch(weekday) // Translates weekday's numeric value and prints it to the screen.
	{
		case 0:
			printf("It's a Saturday.\n");
			break;
		case 1:
			printf("It's a Sunday.\n");
			break;
		case 2:
			printf("It's a Monday.\n");
			break;
		case 3:
			printf("It's a Tuesday.\n");
			break;
		case 4:
			printf("It's a Wednesday.\n");
			break;
		case 5:
			printf("It's a Thursday.\n");
			break;
		case 6:
			printf("It's a Friday.\n");
			break;
	}
	
	int newyear = year+1;
	int counter = 0;
	for(; newyear<=endyear; newyear++)  // calculates how many times the given day-and-month falls on the same weekday
	{
		int newj = newyear/100;
		int newk = newyear%100;
		int newweekday = (day + 13*(month+1)/5 + newk + newk/4 + newj/4 + 5*newj)%7;
		if(newweekday==weekday)
		{
			counter += 1;
		}
		
	}
	
	printf("Same day-and-month on same weekday between %d and %d: %d\n",realyear+1,endyear,counter);
	
	
	return EXIT_SUCCESS; // Terminates the program successfully.
}

