/*
	Alp Eren Genço?lu 150170019
	
	This program determines the empty slot which 
	has the largest distance to the nearest car
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

/**
 *Computes the absolute value of the number
 *@param num number
 *@return absolute value
*/
int absolute(int num)
{
	if(num<0) return -num;
	else return num;
}

/**
 *Computes manhattan distance beetween two locations
 *@param x1 x coordinate of the first location
 *@param y1 y coordinate of the first location
 *@param x2 x coordinate of the second location
 *@param y2 y coordinate of the second location
 *@return manhattan distance
*/
int manhattanDistance(int x1, int y1, int x2, int y2)
{
	int sum = 0;
	sum += (absolute(x1-x2) + absolute(y1-y2));
	return sum;
}

int main()
{
	int parking_area[SIZE][SIZE]={{0}}; // array for parking area grid
	int car_locations[SIZE*SIZE][2]; // array to keep coordinates of the cars
	int csize; // actual size (current size) of the parking area determined by user input
	int cars; // number of cars
	int i,j,k; // for loop variables
	int x,y; // for coordinates of the cars, determined by user input
	int temp_closest=0, closest; // distance between the slot and the closest car
	int distance; // return value of manhattan distance will be assigned here
	int bestx=0, besty=0; // best slot's x and y coordinates to be printed in the screen when the program ends
	
	printf("Size: ");
	scanf("%d",&csize);
	while(csize>50 || csize<1)
	{	
		printf("Size must be between 50 and 1");
		printf("Size: ");
		scanf("%d",&csize);
	}
	
	printf("Cars: ");
	scanf("%d",&cars);
	if(cars==csize*csize) // If There is no place in the parking area, exit without asking locations
	{
		printf("Best Slot Found In: %d %d\n",bestx,besty);
		return EXIT_SUCCESS;
	}
	if(cars>csize*csize) // Error if number of cars exceeds the size of the parking area
	{
		printf("Number of cars cannot exceed the limits of the parking area!");
		return EXIT_FAILURE;
	}
	
	for(i=0;i<cars;i++) // gets locations of the cars from the user
	{
		printf("Locations: ");
		scanf("%d %d",&x,&y);
		
		if(x<1 || x>csize || y<1 || y>csize) // if user enters invalid coordinates, dismiss those
		{
			cars--;
			i--;
			continue;
		}
		
		parking_area[csize-y][x-1]=1;
		car_locations[i][0]=x;
		car_locations[i][1]=y;
	}
	
	
	for(i=1; i<=csize; i++) // Finds the best slot to park by calculating manhattan distance
	{
		for(j=1; j<=csize; j++)
		{
			if(parking_area[i][j]==0)
			{
				temp_closest = 2*csize-2;
				for(k=0; k<cars; k++)
				{
					distance = manhattanDistance(i,j,car_locations[k][0],car_locations[k][1]);
					if (distance<temp_closest)
					{
						temp_closest=distance;
					}
				}
				if(temp_closest>closest)
				{
					closest=temp_closest;
					bestx = i;
					besty = j;
				}
			}
		}
	}
	
	printf("Best Slot Found In: %d %d\n",bestx,besty);
	return EXIT_SUCCESS;
}
