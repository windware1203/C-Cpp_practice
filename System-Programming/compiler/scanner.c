#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DEFAULT_OUTPUT_FILENAME "output.txt"



int
main (int argc, char* args[])
{
    if(argc != 2 && argc != 4)
    {
        printf("usage: %s <input file> <output file>\n", args[0]);
        return EXIT_SUCCESS;
    }


    FILE* fin = fopen(args[1], "r");
    if(!fin)
    {
        perror("missing input file");
        return EXIT_FAILURE;
    }

    const char* output_filename = (argc == 3 ? args[2] : DEFAULT_OUTPUT_FILENAME);
    FILE* fout = fopen(output_filename, "w");
    if(!fout)
    {
        perror("Fatal error");
        return EXIT_FAILURE;
    }

    fclose(fin);
    fclose(fout);
    return 0;
}