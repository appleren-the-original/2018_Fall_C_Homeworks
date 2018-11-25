/*
	Alp Eren Gençoğlu 150170019
	BLG 102E Assignment2
	
	This program gets the target value and a sequence of throws
	from the user, and tracks the point value along the game.
*/

#include <stdio.h> // printf & scanf
#include <stdlib.h> // EXIT_SUCCESS

/*
	* Computes the point value of the throw
	* @param segment the segment of the throw
	* @param ring the ring of the throw
	* @return the score
*/
int point_value(int segment, char ring)
{
	int score;
	switch(ring)
	{
		case 'S':
			score = segment*1;
			break;
		case 'D':
			score = segment*2;
			break;
		case 'T':
			score = segment*3;
			break;
		case 'O':
			score = 25;
			break;
		case 'I':
			score = 50;
			break;
	}
	return score;
}

/*
	* Calcualtes the remaining points after the throw
	* @param cpoints current points (points before t he throw)
	* @param target the target point value
	* @param segment the segment of the throw
	* @param ring the ring of the throw
	* @return remaining points
*/
int remaining_points(int cpoints, int target, int segment, char ring)
{
	int score = point_value(segment,ring);
	if (cpoints == target && ring!='D')
		return cpoints;
	else 
	{
		if ( cpoints>score+1 )		
			return (cpoints-score);
		else if(cpoints==score+1)
			return cpoints;
		else if (cpoints==score)
			if(ring!='D')
				return cpoints;
			else
				return cpoints-score;
		else 
			return cpoints;
	}
}

int main() // The main function which reads inputs from the user and prints out the score after every throw.
{
	int target; // user's target value input
	int current_points; // remaining points variable
	int segment; // segment of the throw (user input)
	char ring; // ring of the throw (user input)
	
	printf("Target: ");
	scanf("%d",&target);
	printf("\n");
	
	current_points = target;
	
	do // reads input and prints the result each loop. 
	{
		printf("Throw: ");
		scanf("%d %c",&segment,&ring);
		current_points = remaining_points(current_points, target, segment, ring);
		printf("Points: %d\n",current_points);
	}
	while(current_points != 0);
	
	return EXIT_SUCCESS; // Terminates the program successfully.
}