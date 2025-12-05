#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Check if a string is a keyword
int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "main", "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef",
        "unsigned", "void", "printf", "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char code[] =
        "main() {\n"
        "  int a, b, c;\n"
        "  // This is a comment\n"
        "  a = b + c;\n"
        "  printf(\"%d\", a);\n"
        "  /* multi-line comment */\n"
        "}";

    char buffer[100];
    int i = 0, j = 0;

    printf("Tokens found:\n\n");

    while (code[i] != '\0') {
        // Skip spaces, tabs, newlines
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // Skip single-line comment
        if (code[i] == '/' && code[i + 1] == '/') {
            i += 2;
            while (code[i] != '\n' && code[i] != '\0') i++;
            continue;
        }

        // Skip multi-line comment
        if (code[i] == '/' && code[i + 1] == '*') {
            i += 2;
            while (code[i] != '\0' && !(code[i] == '*' && code[i + 1] == '/')) i++;
            if (code[i] != '\0') i += 2;
            continue;
        }

        // Detect operators
        if (strchr("+-*/=%", code[i])) {
            printf("%c is operator\n", code[i]);
            i++;
            continue;
        }

        // Detect keywords and identifiers
        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';

            if (isKeyword(buffer))
                printf("%s is keyword\n", buffer);
            else
                printf("%s is identifier\n", buffer);
            continue;
        }

        // Ignore other characters
        i++;
    }

    return 0;
}
