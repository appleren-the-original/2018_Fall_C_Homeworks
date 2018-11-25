/*
	Alp Eren Gençoðlu 150170019
	Assignment 4 | 14.05.2018
	
	This program finds specific words from a book 
	with the help of instructions given (line number 
	and word number in that line) and stores them in
	a sentence then prints the sentence.
	
*/

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>

struct instruction_s
{
	int step;
	int index;
};

/**
 * Removes a character from a string
 * @param s the string to be operated
 * @param index index of the character to be removed
 * @return no return
 */
void removeChar(char* s, int index)
{
	int len = strlen(s);
	int i;
	for(i=index; i<len; i++)
	{
		s[i] = s[i+1];
	}
}

/**
 * Removes all punctuation from a string and lowercases it
 * @param s the string to be operated
 * @return no return
 */
void lowerAndRemovePunc(char* s)
{
	int i,len=strlen(s);
	for(i=0; i<len; i++)
	{
		if(ispunct(s[i]))
		{
			removeChar(s,i);
			i--;
			continue;
		}
		else
			s[i] = tolower(s[i]);
	}
}

/**
 * Extracts a word from a string
 * @param s the string from which a word to be extracted
 * @param n place of the word to be extracted
 * @return extracted word's adress
*/
char* get_word(char* s, int n)
{
	char* token;
	token = (char*) malloc(sizeof(char)*200);
	int i=0;
	if(n==1)
	{
		token=strtok(s," "); 
		return token;
	}
	else
	{
		token=strtok(s," ");
		while(token!=NULL)
		{
			token = strtok(NULL," ");
			if(i==(n-2)) break;
			i++;
		}
	}
	return token;
}

/**
 * Creates a sentence from the words extracted
 * @param lines all lines (string array) of the book
 * @param instructions the struct array in which instructions are stored
 * @param sentence the initially empty string in which the extracted words to be stored
 * @return no return
*/
void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence)
{
	char word[200];
	int i;
	int line_number = -1;
	char linecopy[200];
	for(i=0; i<n_instructions-1; i++)
	{
		line_number += instructions[i].step;
		strcpy(linecopy,lines[line_number]);
		strcpy(word, get_word(linecopy,instructions[i].index));
		lowerAndRemovePunc(word);
		strcat(sentence, word);
		if(i!=n_instructions-2)
			strcat(sentence," ");
	}
	for(i=0; i<strlen(sentence); i++)
	{
		if(sentence[i]=='\n' || sentence[i]=='\r')
		{
			removeChar(sentence,i);
			i--;
		}
	}
}



int main(int argc, char* argv[])
{
	
	if(argc > 3)
	{
		printf("Too many arguments!\n");
		return EXIT_FAILURE;
	}
	else if(argc < 3)
	{
		printf("Not enough arguments!\n");
		return EXIT_FAILURE;
	}
	
	int ctr=0;
	int n_instructions;
	struct instruction_s instructions[10000];
	char* lines[10000];
	char* sentence;
	
	FILE *bookptr;
	FILE *instructionsptr;
	
	
	
	// instrucions file operations
	instructionsptr = fopen(argv[2],"r");
	if(instructionsptr==NULL)
	{
		printf("File cannot be opened.");
		return EXIT_FAILURE;
	}
	else
	{	
		while(!feof(instructionsptr))
		{
			fscanf(instructionsptr,"%d %d",&instructions[ctr].step,&instructions[ctr].index);
			ctr++;
		}
		n_instructions = ctr;
	}
	ctr = 0;
	fclose(instructionsptr);
	
	
	
	// book file operations
	bookptr = fopen(argv[1],"r");
	if(bookptr==NULL)
	{
		printf("File cannot be opened.");
		return EXIT_FAILURE;
	}
	else
	{
		while(!feof(bookptr))
		{
			lines[ctr] = (char*) malloc(sizeof(char)*200);
			fgets(lines[ctr],200,bookptr);
			ctr++;
		}
	}
	ctr = 0;
	fclose(bookptr);
	
	
	// sentence creating and printing
	sentence = (char*) malloc(sizeof(char)*200*n_instructions);
	sentence[0] = '\0';
	get_sentence(lines, instructions, n_instructions, sentence);
	printf("%s",sentence);
	
	return 0;
}

//gcc -std=c99 -Wall -Werror assignment4.c -o assignment4





















