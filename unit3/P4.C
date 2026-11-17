
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
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
    free(temp);
}

void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deleteSpecific() {
    struct node *temp, *prev;
    int key;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
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

        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
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
