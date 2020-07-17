#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabcount.h"



int main(int argc, char *argv[])
{

	// Convert command line argument for desired tabcount to int
	char *a = argv[1];
	int myTabs = atoi(a);


	// Initialize c to read through file by character
	int c;

	// Initialize pointer to line in file
	char *line;

	// Open file
	FILE *fp = fopen("ex_input.txt","r"); 
	if (fp==NULL)
	{
		printf("file cannot be opened\n");
		exit(0);
	}
	
	// Set tabcounter to zero
	int tabs=0;

	// Initialize int for memory allocation
	int linelength=0;
	
	// Initialize file seeker
	int filseek = 0;

	// Initialize file for good rows and bad rows separately
	FILE *goodfile = fopen("goodfile.txt","w");
	FILE *badfile = fopen("badfile.txt","w");
	int i = 0;

	// The first line of the input file is the header row
	while((c = fgetc(fp)) != '\n')
	{
		fprintf(goodfile,"%c",c);
		linelength++;

	}
	
	// The header row will always be in the good file
	fprintf(goodfile,"\n");

	// Move the file seeker pointer to the beginning of the next line after the header line
	// Set the linelength counter to zero
	
	filseek = linelength+1;
	linelength=0;
	
	// Enter the loop until the end of input file
	while((c=fgetc(fp)) != EOF)
	{
		//Grow the linelength until you reach a newline character
		linelength++;
		//printf("%c",c);
		if(c == '\n')
		{
			
			// Allocate memory for the line
			line = calloc((linelength+1),sizeof(char));

			//Move the file seeker again back to the end of the line
			fseek(fp,(-linelength),SEEK_CUR);

			// Read the line to line
			fgets(line,(linelength),fp);

			// Count the amount of tabs in your line
			tabs=tabcount(line);

			// In our example file, the *correct* amount of tabs in a line is 15
			// Also each *correct* line starts with a standard character, in this case a dash (-) 
			// Both of these are given as command line arguments. Compile the program and run as ./<program_name> 15 -
			if(tabs == myTabs && line[0] == *argv[2]) 
			{
				//Print a line with the desired properties to the good file
				for(i = 0; i<=linelength;i++)
				{
					fprintf(goodfile,"%c",line[i]);
				}
				fprintf(goodfile,"\n");
			}

			// Otherwise print the line to badfile
			else
			{
				for(i = 0; i<=linelength;i++)
				{
					fprintf(badfile,"%c",line[i]);
				}
				fprintf(badfile,"\n");
			}

			//Free the line
			free(line);

			//Move the fileseek to the beginning of the next line
			filseek = filseek+linelength;
			fseek(fp,(filseek),SEEK_SET);
			
			//Set linelength to zero
			linelength=0;
		}
		
	}	



fclose(fp);
fclose(goodfile);
fclose(badfile);

}









