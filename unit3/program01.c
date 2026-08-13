/* Write a program to perform following operation on singly linked list:
a. Create a linked list
b. Display it */
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    printf("\nSingly Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    head = createList(n);

    // Display linked list
    display(head);

    return 0;
}
