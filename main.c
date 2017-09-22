#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "simplecalc.h"

int main(int argc, char* argv[])
{
	/* Parse the input file name */
	if (argc != 2) {
		fprintf(stderr, "Usage: %s [input_file]\n", argv[0]);
		return 1;
	}
	char * input_fn = argv[1];

	/* Open the input file in read-only mode, convert to FILE* stream */
	FILE * fp = fopen(input_fn, "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open input file %s: %s\n",
				input_fn, strerror(errno));
	}

	// Call into your simple calc implementation
	return simplecalc(fp);
}
