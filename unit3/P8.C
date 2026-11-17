
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteLast() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteSpecific() {
    struct node *temp;
    int key;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int n, i;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    printf("\nOriginal List: ");
    display();

    deleteFirst();
    printf("After deleting first node: ");
    display();

    deleteLast();
    printf("After deleting last node: ");
    display();

    deleteSpecific();
    printf("After deleting specific node: ");
    display();

    return 0;
}
