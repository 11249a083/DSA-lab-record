#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char data;
    struct node *next;
};

struct node *top = NULL;

// Function to push an element onto stack
void push(char x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Function to pop an element from stack
char pop() {
    if (top == NULL)
        return -1;
    char x = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return x;
}

// Function to get precedence
int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

// Function to peek top element
char peek() {
    if (top != NULL)
        return top->data;
    else
        return -1;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char ch, x;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (top != NULL && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        // If operator
        else {
            while (top != NULL && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining elements
    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // End string

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
