/**
 * @file scanner.c
 * 
 * @author takedaNana (wind.ware1203@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-28
 * 
 * @copyright Copyright (c) 2023
 * reference: 王冠中U10516045.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h> 


#define DEFAULT_OUTPUT_FILENAME "output.txt"

#define TOKEN_SC   0 // single-line comment
#define TOKEN_MC   1 // multi-line comment
#define TOKEN_PREP 2 // preprocessor directive
#define TOKEN_SPEC 3 // special symbol
#define TOKEN_REWD 4 // reserved word
#define TOKEN_CHAR 5 // char literal
#define TOKEN_STR  6 // string literal
#define TOKEN_FLT  7 // float
#define TOKEN_OPER 8 // operator
#define TOKEN_IDEN 9 // identifier
#define TOKEN_INT 10 // interger literal

// Utility functions prototypes
static void ungets(char* s, FILE* fin);
static bool is_newline(char c);
static bool is_whitespace(char c);
static bool is_alphabet(char c);
static bool is_digit(char c);
static bool is_underscore(char c);
static bool is_hex_digit(char c);




// Utility functions
static void ungets(char* s, FILE* fin) {
  for (int i = strlen(s) - 1; i >= 0; i--) {
    ungetc(s[i], fin);
  }
}

static bool is_newline(char c) {
  return c == 0xd || c == 0xa; //LF or CR
}

static bool is_whitespace(char c) {
  return c == ' ' || c == '\t' || is_newline(c);
}

static bool is_alphabet(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

static bool is_underscore(char c) {
  return c == '_';
}

static bool is_hex_digit(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}




int main (int argc, char* args[])
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
    return EXIT_SUCCESS;
}