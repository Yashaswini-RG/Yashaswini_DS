#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

bool isValid(char* s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            if (top == -1)
                return false;

            char topElement = stack[top--];

            if ((s[i] == ')' && topElement != '(') ||
                (s[i] == '}' && topElement != '{') ||
                (s[i] == ']' && topElement != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char s[MAX];

    printf("Enter brackets: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}

