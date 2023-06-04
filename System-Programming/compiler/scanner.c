/**
 * @file scanner.c
 * 
 * @author takedaNana (wind.ware1203@gmail.com)
 * @brief scanning the source code, and split it to the tokens. Get the longest string for a token.
 * @version 0.1
 * @date 2023-04-28
 * 
 * @copyright Copyright (c) 2023
 * reference: 王冠中U10516045.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


#define DEFAULT_INPUT_FILENAME "scanner.c"
#define DEFAULT_OUTPUT_FILENAME "output.txt"

#define REWD_MAX_LEN 10



const char rewds[][REWD_MAX_LEN] = {//25
    "if", "do", "for", "int", "break", "default", "float",
	"double", "case", "else", "extern", "sizeof", "register",
	"while", "enum", "union", "goto", "auto", "char", "const",
	"static", "switch", "continue", "struct", "return"
};

typedef struct 
{
    FILE *fin;
    int line_number;
} FileReader;

typedef void (*TokenScan)(FileReader *fr, FILE *fout);

typedef enum 
{
    IDEN,
    REWD,
    INTE,
    FLOT,
    CHAR,
    STR,
    OPER,
    SPEC,
    SC,
    MC,
    PREP
} TokenType;

// Function prototypes
void *ScanScan(FileReader *fr, FILE *fout, TokenType Opt);
const char *token_type_to_string(TokenType type); 
void report_token(FileReader *fr, FILE *fout, TokenType type, const char *token);
void scan_identifier(FileReader *fr, FILE *fout);
bool scan_reserved(FileReader *fr, FILE *fout, char *buffer);
void scan_integer(FileReader *fr, FILE *fout);
void scan_float(FileReader *fr, FILE *fout);
void scan_character(FileReader *fr, FILE *fout);
void scan_string(FileReader *fr, FILE *fout);
void scan_operator(FileReader *fr, FILE *fout);
void scan_special(FileReader *fr, FILE *fout);
void scan_single_comment(FileReader *fr, FILE *fout);
void scan_multi_comment(FileReader *fr, FILE *fout);
void scan_preprocessor(FileReader *fr, FILE *fout);


int
compare(const void *arg1, const void *arg2) {
  return  (*(int *)arg1 - *(int *)arg2);
}

//A funtion pointer for the Token Scanning 
void ScanToken(FileReader *fr, FILE *fout, TokenScan Opt)
{
     return Opt(fr, fout);
} 

const char*
token_type_to_string(TokenType type) 
{
    switch (type) 
	{
        case IDEN:
            return "IDEN";
        case REWD:
            return "REWD";
        case INTE:
            return "INTE";
        case FLOT:
            return "FLOT";
        case CHAR:
            return "CHAR";
        case STR:
            return "STR";
        case OPER:
            return "OPER";
        case SPEC:
            return "SPEC";
        case SC:
            return "SC";
        case MC:
            return "MC";
        case PREP:
            return "PREP";
        default:
            return "UNKNOWN";
    }
}

void
report_token(FileReader *fr, FILE *fout, TokenType type, const char *token) 
{
    fprintf(fout, "%d\t%-7s\t%s\n", fr->line_number, token_type_to_string(type), token);
}

bool
scan_reserved(FileReader *fr, FILE *fout,char *buffer)
{
    char *ch = bsearch (buffer, rewds, 25,REWD_MAX_LEN , compare);
    if(ch != NULL)
    {
    	report_token(fr, fout, REWD, buffer);
    	return true;
	}
	else
	{
		return false;
	}
}


void
scan_identifier(FileReader *fr, FILE *fout) 
{
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    while ((c = fgetc(fr->fin)) != EOF 
			&& (isalpha(c) || isdigit(c) || c == '_')) 
	{
        buffer[index++] = c;
    }

    buffer[index] = '\0';

    fseek(fr->fin, -1, SEEK_CUR);
    if(!scan_reserved(fr, fout, buffer))
    {
    	report_token(fr, fout, IDEN, buffer);
	}
}

void
scan_integer(FileReader *fr, FILE *fout) 
{
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;

    // Check if the first character is a valid sign (+ or -)
    if (c == '+' || c == '-')
    {
        buffer[index++] = c;
        c = fgetc(fr->fin);
    }
    
    
    int cnt = 1;
    // Read digits until a non-digit character is encountered
    while (isdigit(c)) 
    {
        buffer[index++] = c;
        c = fgetc(fr->fin);
        cnt++;
        if(c == '.')
        {
        	fseek(fr->fin, 0 - cnt, SEEK_CUR);
        	return scan_float(fr, fout);
		}
    }
    fseek(fr->fin,-1, SEEK_CUR);

    // If the last character read is not a digit, move the file pointer back
    if (!isdigit(buffer[index - 1]))
    {
        fseek(fr->fin, -1, SEEK_CUR);
        index--;
    }

    buffer[index] = '\0';

    // Report the token as an integer constant
    report_token(fr, fout, INTE, buffer);
}

void
scan_hexadecimal(FileReader *fr, FILE *fout)
{
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    while ((c = fgetc(fr->fin)) != EOF && isxdigit(c))
    {
        buffer[index++] = c;
    }

    buffer[index] = '\0';

    fseek(fr->fin, -1, SEEK_CUR);
    report_token(fr, fout, INTE, buffer);
}

void
scan_octal(FileReader *fr, FILE *fout)
{
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    while ((c = fgetc(fr->fin)) != EOF && c >= '0' && c <= '7')
    {
        buffer[index++] = c;
    }

    buffer[index] = '\0';

    fseek(fr->fin, -1, SEEK_CUR);
    report_token(fr, fout, INTE, buffer);
}

void
scan_float(FileReader *fr, FILE *fout) 
{
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;

    // Check if the first character is a valid sign (+ or -)
    if (c == '+' || c == '-')
    {
        buffer[index++] = c;
        c = fgetc(fr->fin);
    }

    // Read digits before the decimal point
    while (isdigit(c))
    {
        buffer[index++] = c;
        c = fgetc(fr->fin);
    }

    // Check if there is a decimal point and read digits after it
    if (c == '.')
    {
        buffer[index++] = c;
        c = fgetc(fr->fin);

        // Read digits after the decimal point
        while (isdigit(c))
        {
            buffer[index++] = c;
            c = fgetc(fr->fin);
        }
    }
    else
    {
    	fseek(fr->fin, -index, SEEK_CUR);
    	return;
	}

    // Check if there is an exponent part
    switch (c)
    {
		case 'e':
		case 'E':
	        buffer[index++] = c;
	        c = fgetc(fr->fin);
	
	        // Check if there is a valid sign (+ or -)
	        switch (c)
	        {
	        	case '+':
	        	case '-':
		            buffer[index++] = c;
		            c = fgetc(fr->fin);
		            if (isdigit(c))
					{
						buffer[index++] = c;
			            c = fgetc(fr->fin);
					}
					else
					{
						fseek(fr->fin, -2, SEEK_CUR);
					}
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
	        }
	        // Read digits in the exponent
	        while (isdigit(c))
	        {
	            buffer[index++] = c;
	            c = fgetc(fr->fin);
	        }
	        break;
	    default:
	    	fseek(fr->fin, -1, SEEK_CUR);
	    	break;
	    	
	}

    buffer[index] = '\0';

    // Report the token as a float constant
    report_token(fr, fout, FLOT, buffer);
}




void
scan_character(FileReader *fr, FILE *fout) 
{
    char c;
    char buffer[256];
    int index = 0;

    while ((c = fgetc(fr->fin)) != EOF && c != '\'') 
	{
        buffer[index++] = c;
        
		//process escape character
        if(c == '\\')
	    {
	    	c = fgetc(fr->fin);
	    	buffer[index++] = '\\';
	    	buffer[index++] = c;
		}
    }
    
    if (c == '\'') 
	{
        buffer[index] = '\0';
        report_token(fr, fout, CHAR, buffer);
    } 
	else 
	{
        fprintf(fout, "Invalid character constant at line %d\n", fr->line_number);
    }
}

void
scan_string(FileReader *fr, FILE *fout) 
{
    char c;
    char buffer[256];
    int index = 0;
    int line_start = fr->line_number;

    while ((c = fgetc(fr->fin)) != EOF) 
	{
		//process escape character
		if(c == '\\')
		{
			buffer[index++] = '\\';
			c = fgetc(fr->fin);
			buffer[index++] = c;
			c = fgetc(fr->fin);
		}
		
        if (c == '\"') 
		{
            buffer[index] = '\0';
            report_token(fr, fout, STR, buffer);
            return;
        }
		else if (c == '\n') 
		{
            fprintf(fout, "%d \t STR\t%s \tERROR: missing \"\n", line_start, buffer);
            fr->line_number++;
            return;
        }
		else 
		{
            buffer[index++] = c;
        }
    }

    fprintf(fout, "%d\tSTR\t\t%s  ERROR: missing \"\n", line_start, buffer);
}


void
scan_preprocessor(FileReader *fr, FILE *fout) 
{
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    // Read until the end of the line
    while (c != '\n' && c != EOF) 
	{
        c = fgetc(fr->fin);
        buffer[index++] = c;
    }
    buffer[index - 1] = '\0';
    fr->line_number++;
    report_token(fr, fout, PREP, buffer);
}

void
scan_operator(FileReader *fr, FILE *fout) 
{
    char c = fgetc(fr->fin);
    char ch;
    char buffer[3];
    buffer[0] = c;
    buffer[1] = '\0';

    switch (c) 
	{
        case '+':// +, ++, +=
			ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '+':
					buffer[1] = '+';
					buffer[2] = '\0';
					break;
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
			
        case '-':// -, --, -=, ->
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '-':
					buffer[1] = '-';
					buffer[2] = '\0';
					break;
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				case '>':
					buffer[1] = '>';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '*':// *, *=
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '*':
					buffer[1] = '*';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '/':// /, /=
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
		case '%':// %, %=
			ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '=':// =, ==
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case ',':
        case '>':// >, >>, >=
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '>':
					buffer[1] = '>';
					buffer[2] = '\0';
					break;
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '<':// <, <<, <=
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '<':
					buffer[1] = '<';
					buffer[2] = '\0';
					break;
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '!':// !, !=
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '=':
					buffer[1] = '=';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '&':// &, &&
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '&':
					buffer[1] = '&';
					buffer[2] = '\0';
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '|':// |, ||
        	ch = fgetc(fr->fin);	
			switch(ch)
			{
				case '|':
					buffer[1] = '|';
					buffer[2] = '\0';
					break;
					break;
				default:
					fseek(fr->fin, -1, SEEK_CUR);
					break;
			}
        case '^':
		case '[':
        case ']':
        case '.':
            report_token(fr, fout, OPER, buffer);
            break;
        case '(':
        case ')':
        case '{':
        case '}':
        case ';':
        case '?':
        case ':':
            report_token(fr, fout, SPEC, buffer);
            break;
        default:
            fprintf(fout, "Invalid operator at line %d\n", fr->line_number);
    }
}

void
scan_single_comment(FileReader *fr, FILE *fout) 
{
    char c;

    while ((c = fgetc(fr->fin)) != EOF && c != '\n') 
	{
        // Ignore characters in single-line comments
    }
    report_token(fr, fout, SC, "");
    fr->line_number++;
}

void
scan_multi_comment(FileReader *fr, FILE *fout) 
{
    char c;
    int comment_start_line = fr->line_number;
    while ((c = fgetc(fr->fin)) != EOF) 
	{
        if (c == '*') 
		{
            if ((c = fgetc(fr->fin)) == '/') 
			{
				fprintf(fout, "%d-%d\t%s\n",
						comment_start_line,
						fr->line_number,
						token_type_to_string(MC));
                return;
            }
            else
            {
            	fseek(fr->fin, -1, SEEK_CUR);
			}
        }
		else if (c == '\n') 
		{
            fr->line_number++;
        }
        
    }
	fprintf(fout, "%d-%d\t%s\t\tERROR: missing */\n", comment_start_line, fr->line_number, token_type_to_string(MC));
}

void
scan_tokens(FileReader *fr, FILE *fout) 
{
    char c;

    while ((c = fgetc(fr->fin)) != EOF)
    {
        if (isspace(c))
        {
            if(c == '\n')
	        {
	        	fr->line_number++;
			}
        }
        else if (isalpha(c) || c == '_')
        {
            fseek(fr->fin, -1, SEEK_CUR);
            ScanToken(fr, fout, scan_identifier);
        }
        else if (isdigit(c))
        {
            fseek(fr->fin, -1, SEEK_CUR);
            if (c == '0')
            {
                // Check for hexadecimal or octal constant
                char nextChar = fgetc(fr->fin);
                if (nextChar == 'x' || nextChar == 'X')
                {
                    // Hexadecimal constant
                    fseek(fr->fin, -1, SEEK_CUR);
                    ScanToken(fr, fout, scan_hexadecimal);
                }
                else
                {
                    // Octal constant
                    fseek(fr->fin, -1, SEEK_CUR);
                    ScanToken(fr, fout, scan_octal);

                }
            }
            else
            {
                ScanToken(fr, fout, scan_integer);
            }
        }
        else if (c == '\'')
        {
            ScanToken(fr, fout, scan_character);
        }
        else if (c == '\"')
        {
            ScanToken(fr, fout, scan_string);
        }
        else if (c == '/')
        {
        	c = fgetc(fr->fin);
            if (c == '/')
            {
                ScanToken(fr, fout, scan_single_comment);
            }
            else if (c == '*')
            {
                ScanToken(fr, fout, scan_multi_comment);
            }
            else
            {
                fseek(fr->fin, -1, SEEK_CUR);
               ScanToken(fr, fout, scan_operator);
            }
        }
        else if (c == '.')
        {
        	fseek(fr->fin, -1, SEEK_CUR);
        	ScanToken(fr, fout, scan_float);
		}
        else if (c == '#')
        {
            fseek(fr->fin, -1, SEEK_CUR);
            ScanToken(fr, fout, scan_preprocessor);
        }
        else if (c == '+' || c == '-' || c == '.')
        {
            char nextChar = fgetc(fr->fin);
            if (isdigit(nextChar))
            {
                fseek(fr->fin, -1, SEEK_CUR);
                ScanToken(fr, fout, scan_float);
            }
            else
            {
                fseek(fr->fin, -2, SEEK_CUR);
                ScanToken(fr, fout, scan_operator);
            }
        }
        else
        {
            fseek(fr->fin, -1, SEEK_CUR);
            ScanToken(fr, fout, scan_operator);
        }
        
        c = fgetc(fr->fin);
        if(c == '\n')
        {
        	fr->line_number++;
		}
		else
		{
			fseek(fr->fin, -1, SEEK_CUR);
		}
    }
}

int
main() 
{
	//init
    FileReader* fr = (FileReader*) malloc(sizeof(FileReader));
    fr->fin = fopen(DEFAULT_INPUT_FILENAME, "r");
    fr->line_number = 1;
    
    //file opening
    FILE *fout = fopen(DEFAULT_OUTPUT_FILENAME, "w");

    if (fr->fin == NULL || fout == NULL) 
	{
        fprintf(stderr, "Error opening files.\n");
        return EXIT_FAILURE;
    }
    
    ScanToken(fr, fout, scan_tokens);

    fclose(fr->fin);
    fclose(fout);
    free(fr);
    
	printf("The output is sucessful in %s",DEFAULT_OUTPUT_FILENAME);
    return EXIT_SUCCESS;
}
