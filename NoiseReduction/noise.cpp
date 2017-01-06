#include <stdio.h>
#include <stdlib.h>

char **image_n()
{
	int r=101,c=120; //numbers for rows and columns
	FILE *file; //file pointer
	int x; // loop variables
	char **im=(char **) malloc(r*sizeof(char *)); //image
	for(x=0; x<r; x++)
    {
        im[x]=(char *) malloc(c*sizeof(char));
    }
    file = fopen("noise.txt" , "r"); //open image for reading
    if (file == NULL)  // error while opening
    {
        printf("!!! ERROR. FILE NAME MUST BE 'noise.txt'. !!!");
    }
    while (!feof(file)) // read image
	{
	    for(x=0; x<r; x ++)
        {
			fread(im[x],sizeof(char),c+1,file);
        }
	}
    fclose(file); // close file
    return im;
}
