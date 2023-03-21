#include "cdecomp.h"

#include <stdio.h>
#include <string.h>


int main (int argc, char *argv[])
{

	printf("%s", argv[0]);
	FILE *infile, *outfile;
	if (argc != 3){
		printf("\n");
		printf("Usage: infile outfile\n");
		return 1;
	} else if ((infile=fopen(argv[1],"rb"))==NULL){
		printf("Error opening input %s\n",argv[1]);
		return 1;
	} else if ((outfile=fopen(argv[2],"wb"))==NULL){
		printf("Error opening output %s\n",argv[2]);
		return 1;
	} else {

		expand(infile,outfile);

		fclose(outfile);
		fclose(infile);
		return 0;
	}
}
