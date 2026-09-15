#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert AFTER a specific value
void insertAfter(struct Node* head, int target, int val) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found.\n", target);
        return;
    }
    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", val, target);
}

// Insert BEFORE a specific value
struct Node* insertBefore(struct Node* head, int target, int val) {
    if (head == NULL) return NULL;

    // If target is the first node
    if (head->data == target) {
        struct Node* newNode = createNode(val);
        newNode->next = head;
        printf("Inserted %d before %d.\n", val, target);
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value %d not found.\n", target);
        return head;
    }

    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d before %d.\n", val, target);
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, val, target;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create/Append Node\n");
        printf("2. Insert After\n");
        printf("3. Insert Before\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                if (head == NULL) {
                    head = createNode(val);
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = createNode(val);
                }
                break;
            case 2:
                printf("Enter target value to insert after: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &val);
                insertAfter(head, target, val);
                break;
            case 3:
                printf("Enter target value to insert before: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &val);
                head = insertBefore(head, target, val);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
