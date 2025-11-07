#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

void push(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
        printf("Stack Overflow\n");
    else {
        newnode->data = val;
        newnode->link = top;
        top = newnode;
        printf("%d pushed into stack\n", val);
    }
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow\n");
    else {
        struct node *temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->link;
        free(temp);
    }
}

void peek() {
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element is: %d\n", top->data);
}

int main() {
    // Example operations
    push(10);
    push(20);
    push(30);

    peek();    // Should print 30
    pop();     // Removes 30
    peek();    // Now top is 20
    pop();     // Removes 20
    pop();     // Removes 10
    pop();     // Stack underflow

    return 0;
}
