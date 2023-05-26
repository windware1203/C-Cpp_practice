#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>

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

void scan_tokens(FileReader* fr, FILE* fout) {
    char line[256];
    regex_t regex;
    regmatch_t matches[2];
    int reti;

    const char* identifier_pattern = "^[a-zA-Z_][a-zA-Z0-9_]*";
    const char* reserved_words_pattern = "^(if|else|while|for|do|switch|case|default|continue|int|long|float|double|char|break|static|extern|auto|register|sizeof|union|struct|short|enum|return|goto|const|signed|unsigned|typedef|void)\\b";
    const char* integer_pattern = "^[-+]?[0-9]+";
    const char* float_pattern = "^[-+]?([0-9]+\\.[0-9]*|[0-9]*\\.[0-9]+)([eE][-+]?[0-9]+)?";
    const char* character_pattern = "^'[^']*'";
    const char* string_pattern = "^\"[^\"]*\"";
    const char* operator_pattern = "^([+\\-*/=,%><!&|^]|\\[|\\]|\\(|\\)|\\{|\\}|;|\\?|:|\\.|->|==|>=|<=|!=)";
    const char* preprocessor_pattern = "^#\\s*(\\w+).*";

    // Compile regular expressions
    reti = regcomp(&regex, identifier_pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex for identifiers\n");
        exit(EXIT_FAILURE);
    }

    // Add other regular expressions for different token types

    while (fgets(line, sizeof(line), fr->fin)) {
        fr->line_number++;

        char* token = strtok(line, " \t\n");
        while (token != NULL) {
            // Match against each regular expression
            reti = regexec(&regex, token, 2, matches, 0);
            if (reti == 0 && matches[0].rm_so == 0) {
                report_token(fr, fout, IDEN, token);
            } else {
                // Check against other regular expressions and report tokens accordingly
                // You can use similar regexec calls for other token types
                reti = regexec(&regex_preprocessor, token, 2, matches, 0);
                if (reti == 0 && matches[0].rm_so == 0) {
                    report_token(fr, fout, PREP, token);
                } else {
                    // Handle other token types
                }
            }

            token = strtok(NULL, " \t\n");
        }
    }

    // Free regex resources
    regfree(&regex);
}

int main() {
    FileReader fr;
    fr.fin = fopen("input.c", "r");
    fr.line_number = 0;
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
