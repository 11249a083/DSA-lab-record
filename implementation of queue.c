#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global pointers for front and rear
struct node *front = NULL;
struct node *rear = NULL;

// Function to insert (enqueue)
void enqueue(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued: %d\n", value);
}

// Function to delete (dequeue)
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct node *temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Function to display all elements
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to peek (front element)
void peek() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Front element: %d\n", front->data);
}

int main() {
    printf("Queue Implementation using Linked List\n\n");

    // Performing all operations once
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();  // Display all elements

    peek();     // Show front element

    dequeue();  // Delete one element

    display();  // Display after deletion

    peek();     // Show new front

    return 0;
}
