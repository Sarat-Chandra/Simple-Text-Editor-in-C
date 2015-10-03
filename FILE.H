#include<stdio.h>

//char OldName[20];
//char NewName[20];
extern int LAST;
extern char buffer[200][80];
WriteFile(char* filename)
{
 FILE *destination;
 int i;
 destination = fopen(filename,"w");

 for(i=0;i<LAST;i++)
	    fprintf(destination,"%s\n",buffer[i]);
 return 0;
}