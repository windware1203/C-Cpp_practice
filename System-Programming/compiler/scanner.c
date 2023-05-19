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

enum {
  TOKEN_SC,   // single-line comment
  TOKEN_MC,   // multi-line comment
  TOKEN_PREP, // preprocessor directive
  TOKEN_SPEC, // special symbol
  TOKEN_REWD, // reserved word
  TOKEN_CHAR, // char literal
  TOKEN_STR,  // string literal
  TOKEN_FLT, // float
  TOKEN_OPER, // operator
  TOKEN_IDEN, // identifier
  TOKEN_INT, // interger literal
  TOKEN_LAST
};

// Lex functions prototypes
static bool scan_sc(FileReader* fr, FILE* fout);
static bool scan_mc(FileReader* fr, FILE* fout);
static bool scan_prep(FileReader* fr, FILE* fout);
static bool scan_spec(FileReader* fr, FILE* fout);
static bool scan_rewd(FileReader* fr, FILE* fout);
static bool scan_char(FileReader* fr, FILE* fout);
static bool scan_str(FileReader* fr, FILE* fout);
static bool scan_flot(FileReader* fr, FILE* fout);
static bool scan_oper(FileReader* fr, FILE* fout);
static bool scan_iden(FileReader* fr, FILE* fout);
static bool scan_inte(FileReader* fr, FILE* fout);

// Utility functions prototypes
static void ungets(char* s, FILE* fin);
static bool is_newline(char c);
static bool is_whitespace(char c);
static bool is_alphabet(char c);
static bool is_digit(char c);
static bool is_underscore(char c);
static bool is_hex_digit(char c);


static bool scan_sc(FileReader* fr, FILE* fout)
{

}

static bool scan_mc(FileReader* fr, FILE* fout)
{

}

static bool scan_prep(FileReader* fr, FILE* fout)
{

}

static bool scan_spec(FileReader* fr, FILE* fout)
{

}

static bool scan_rewd(FileReader* fr, FILE* fout)
{

}
static bool scan_char(FileReader* fr, FILE* fout)
{

}
static bool scan_str(FileReader* fr, FILE* fout)
{

}
static bool scan_flot(FileReader* fr, FILE* fout)
{

}

static bool scan_oper(FileReader* fr, FILE* fout)
{


}

static bool scan_iden(FileReader* fr, FILE* fout)
{

}

static bool scan_inte(FileReader* fr, FILE* fout)
{

}


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