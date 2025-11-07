#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at beginning
void insertBegin(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// 2. Insert at end
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// 3. Insert at specific position
void insertPos(int value, int pos) {
    struct Node *newNode = createNode(value);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// 4. Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// 5. Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
        head = NULL; // Only one node
    else
        prev->next = NULL;
    free(temp);
}

// 6. Delete from position
void deletePos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}



// 8. Display the list
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    
    insertBegin(10);
    insertEnd(20);
    insertEnd(30);
    printf("after insertion:\n");
    display();
    deleteBegin();
    display();
    deleteEnd();
    display();
    return 0;
}
