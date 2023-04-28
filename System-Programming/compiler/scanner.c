/**
 * @file scanner.c
 * 
 * @author takedaNana (wind.ware1203@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define DEFAULT_OUTPUT_FILENAME "output.txt"

#define TOKEN_SC   0 // single-line comment
#define TOKEN_MC   1 // multi-line comment
#define TOKEN_PREP 2 // preprocessor directive
#define TOKEN_SPEC 3 // special symbol
#define TOKEN_REWD 4 // reserved word
#define TOKEN_CHAR 5 // char literal
#define TOKEN_STR  6 // string literal
#define TOKEN_FLOT 7 // float
#define TOKEN_OPER 8 // operator
#define TOKEN_IDEN 9 // identifier
#define TOKEN_INTE 10 // interger literal




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