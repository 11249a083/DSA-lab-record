#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
};

struct node *top = NULL;

// Function to push element onto stack
void push(char c) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = c;
    newnode->next = top;
    top = newnode;
}

// Function to pop element from stack
char pop() {
    if (top == NULL)
        return '\0';
    char c = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return c;
}

// Function to check matching brackets
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Main function
int main() {
    char exp[100];
    int i, flag = 1;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == NULL) {
                flag = 0; // closing bracket with no opening
                break;
            }
            char popped = pop();
            if (!isMatchingPair(popped, ch)) {
                flag = 0; // mismatched pair
                break;
            }
        }
    }

    if (top != NULL) // leftover opening brackets
        flag = 0;

    if (flag)
        printf("The expression is Balanced.\n");
    else
        printf("The expression is Not Balanced.\n");

    return 0;
}
