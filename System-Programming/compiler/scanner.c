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
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    FILE* fin;
    int line_number;
} FileReader;

typedef enum {
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
void report_token(FileReader* fr, FILE* fout, TokenType type, const char* token);
void scan_identifier(FileReader* fr, FILE* fout);
void scan_reserved(FileReader* fr, FILE* fout);
void scan_integer(FileReader* fr, FILE* fout);
void scan_float(FileReader* fr, FILE* fout);
void scan_character(FileReader* fr, FILE* fout);
void scan_string(FileReader* fr, FILE* fout);
void scan_operator(FileReader* fr, FILE* fout);
void scan_special(FileReader* fr, FILE* fout);
void scan_single_comment(FileReader* fr, FILE* fout);
void scan_multi_comment(FileReader* fr, FILE* fout);
void scan_preprocessor(FileReader* fr, FILE* fout);

const char* token_type_to_string(TokenType type) {
    switch (type) {
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

void report_token(FileReader* fr, FILE* fout, TokenType type, const char* token) {
    fprintf(fout, "%d\t%s\t%s\n", fr->line_number, token_type_to_string(type), token);
}

void scan_identifier(FileReader* fr, FILE* fout) {
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    while ((c = fgetc(fr->fin)) != EOF && (isalpha(c) || isdigit(c) || c == '_')) {
        buffer[index++] = c;
    }

    buffer[index] = '\0';

    fseek(fr->fin, -1, SEEK_CUR);
    report_token(fr, fout, IDEN, buffer);
}

void scan_integer(FileReader* fr, FILE* fout) {
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    while ((c = fgetc(fr->fin)) != EOF && isdigit(c)) {
        buffer[index++] = c;
    }

    buffer[index] = '\0';

    fseek(fr->fin, -1, SEEK_CUR);
    report_token(fr, fout, INTE, buffer);
}

void scan_float(FileReader* fr, FILE* fout) {
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    while ((c = fgetc(fr->fin)) != EOF && (isdigit(c) || c == '.' || c == 'E' || c == 'e' || c == '+' || c == '-')) {
        buffer[index++] = c;
    }

    buffer[index] = '\0';

    fseek(fr->fin, -1, SEEK_CUR);
    report_token(fr, fout, FLOT, buffer);
}

void scan_character(FileReader* fr, FILE* fout) {
    char c;
    char buffer[256];
    int index = 0;

    while ((c = fgetc(fr->fin)) != EOF && c != '\'') {
        buffer[index++] = c;
    }

    if (c == '\'') {
        buffer[index] = '\0';
        report_token(fr, fout, CHAR, buffer);
    } else {
        fprintf(fout, "Invalid character constant at line %d\n", fr->line_number);
    }
}

void scan_string(FileReader* fr, FILE* fout) {
    char c;
    char buffer[256];
    int index = 0;
    int line_start = fr->line_number;

    while ((c = fgetc(fr->fin)) != EOF) {
        if (c == '\"') {
            buffer[index] = '\0';
            report_token(fr, fout, STR, buffer);
            return;
        } else if (c == '\n') {
            fprintf(fout, "%d\tSTR\t\t%s  ERROR: missing \"\n", line_start, buffer);
            fr->line_number++;
            return;
        } else {
            buffer[index++] = c;
        }
    }

    fprintf(fout, "%d\tSTR\t\t%s  ERROR: missing \"\n", line_start, buffer);
}


void scan_preprocessor(FileReader* fr, FILE* fout) {
    char c = fgetc(fr->fin);
    char buffer[256];
    int index = 0;
    buffer[index++] = c;

    // Read until the end of the line
    while (c != '\n' && c != EOF) {
        c = fgetc(fr->fin);
        buffer[index++] = c;
    }
    buffer[index - 1] = '\0';

    report_token(fr, fout, PREP, buffer);
}

void scan_operator(FileReader* fr, FILE* fout) {
    char c = fgetc(fr->fin);
    char buffer[3];
    buffer[0] = c;
    buffer[1] = '\0';

    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
        case ',':
        case '%':
        case '>':
        case '<':
        case '!':
        case '&':
        case '|':
        case '^':
        case '.':
            report_token(fr, fout, OPER, buffer);
            break;
        case '[':
        case ']':
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

void scan_single_comment(FileReader* fr, FILE* fout) {
    char c;

    while ((c = fgetc(fr->fin)) != EOF && c != '\n') {
        // Ignore characters in single-line comments
    }
    report_token(fr, fout, SC, "");
    fr->line_number++;
}

void scan_multi_comment(FileReader* fr, FILE* fout) {
    char c;
    int comment_start_line = fr->line_number;

    while ((c = fgetc(fr->fin)) != EOF) {
        if (c == '*') {
            if ((c = fgetc(fr->fin)) == '/') {
                return;
            }
        } else if (c == '\n') {
            fr->line_number++;
        }
    }
    report_token(fr, fout, MC, "");
	fprintf(fout, "%d-%d\t%s\t\tERROR: missing */\n", comment_start_line, fr->line_number, token_type_to_string(MC));
}

void scan_tokens(FileReader* fr, FILE* fout) {
    char c;

    while ((c = fgetc(fr->fin)) != EOF) {
        if (c == '\n') {
            fr->line_number++;
        } else if (isspace(c)) {
            // Ignore whitespace characters
        } else if (isalpha(c) || c == '_') {
            fseek(fr->fin, -1, SEEK_CUR);
            scan_identifier(fr, fout);
        } else if (isdigit(c)) {
            fseek(fr->fin, -1, SEEK_CUR);
            scan_integer(fr, fout);
        } else if (c == '\'') {
            scan_character(fr, fout);
        } else if (c == '\"') {
            scan_string(fr, fout);
        } else if (c == '/') {
            if ((c = fgetc(fr->fin)) == '/') {
                scan_single_comment(fr, fout);
            } else if (c == '*') {
                scan_multi_comment(fr, fout);
            } else {
                fseek(fr->fin, -1, SEEK_CUR);
                scan_operator(fr, fout);
            }
        } else if (c == '#') {
            fseek(fr->fin, -1, SEEK_CUR);
            scan_preprocessor(fr, fout);
        } else {
            fseek(fr->fin, -1, SEEK_CUR);
            scan_operator(fr, fout);
        }
    }
}

int main() {
    FileReader fr;
    fr.fin = fopen("input.c", "r");
    fr.line_number = 1;
    FILE* fout = fopen("tokens.txt", "w");

    if (fr.fin == NULL || fout == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    scan_tokens(&fr, fout);

    fclose(fr.fin);
    fclose(fout);

    return 0;
}
