#include <stdio.h>
#include <ctype.h>
#include <string.h>

void isKeyword(char *str) {
    char keywords[10][10] = {"int", "float", "if", "else", "while", "for", "return", "break", "char", "void"};
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            printf("%s is a keyword\n", str);
            return;
        }
    }
    printf("%s is an identifier\n", str);
}

int main() {
    char str[100], ch;
    int i = 0;

    printf("Enter a simple statement (like 'int a = 5;'):\n");
    fgets(str, sizeof(str), stdin);

    char temp[20];
    int j = 0;

    for (i = 0; i < strlen(str); i++) {
        ch = str[i];
        if (isalnum(ch)) {
            temp[j++] = ch;
        } else {
            if (j != 0) {
                temp[j] = '\0';
                isKeyword(temp);
                j = 0;
            }
            if (ch == '=')
                printf("= is an assignment operator\n");
            else if (ch == ';')
                printf("; is a semicolon\n");
            else if (ch == '+')
                printf("+ is an addition operator\n");
        }
    }

    return 0;
}
