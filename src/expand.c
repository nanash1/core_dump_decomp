/* expand.c */

#include <stdio.h>

/* Decompress data from input to output */
void expand (FILE *input, FILE *output)
{
	int byte;
	int code;
	int copy;
	int flags;

	while ((byte = getc(input)) != EOF) {
		code = byte & 0x3F;					/* 6 LSBs are the number of symbols to copy or to repeat */
		flags = (byte & 0xC0) >> 6;			/* 2 MSBs are flags */

		/* if the LSB of the flags is set, the next byte must be added to the
		 * number of repeats or copies */
		if (flags & 0x1){
			code = (code << 8) | getc(input);
		}

		/* if the MSB of the flags is set, we must copy the data */
		if (flags & 0x2){
			for (int i = 0; i < code; i++){
				putc(getc(input), output);
			}
		/* if the MSB is not set, we must repeat the data */
		} else {
			copy = getc(input);
			for (int i = 0; i < code; i++){
				putc(copy, output);
			}
		}

	}
}
