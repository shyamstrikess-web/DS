
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAfter() {
    struct node *newnode, *temp;
    int key;

    printf("Enter node value after which to insert: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

void insertBefore() {
    struct node *newnode, *temp;
    int key;

    printf("Enter node value before which to insert: ");
    scanf("%d", &key);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == key) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter new data: ");
        scanf("%d", &newnode->data);

        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Node not found\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
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

    insertAfter();
    display();

    insertBefore();
    display();

    return 0;
}
