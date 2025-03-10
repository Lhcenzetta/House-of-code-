#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 1000

bool isValid(const char *s) {
    char stack[MAX_SIZE]; // Separate stack to store opening brackets
    int top = -1; // Stack pointer

    int i = 0; 

    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        // check if it matches the top of the stack
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1) {
                return false; 
            }
            char popped = stack[top--]; // Pop from the stack
            if ((s[i] == ')' && popped != '(') ||
                (s[i] == '}' && popped != '{') ||
                (s[i] == ']' && popped != '[')) {
                return false; 
            }
        }
        i++; // Move to the next character
    }

    // If the stack is empty, all brackets are balanced
    return top == -1;
}

// test the code over here 
int main(void) {
    const char *test1 = "()";
    const char *test2 = "[{()}]";
    const char *test3 = "{[(a+b) * x}";
    const char *test4 = "{[a+b]*(x/y)}";

    printf("Test 1: %s\n", test1);
    printf("Is valid: %d\n", isValid(test1));

    printf("Test 2: %s\n", test2);
    printf("Is valid: %d\n", isValid(test2));

    printf("Test 3: %s\n", test3);
    printf("Is valid: %d\n", isValid(test3));

    printf("Test 4: %s\n", test4);
    printf("Is valid: %d\n", isValid(test4));

    return 0;
}