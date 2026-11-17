
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int x)
{
    if(root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct node *findmin(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

struct node *deleteNode(struct node *root, int x)
{
    struct node *temp;

    if(root == NULL)
        return NULL;

    if(x < root->data)
        root->left = deleteNode(root->left, x);

    else if(x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findmin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int height(struct node *root)
{
    int a, b;

    if(root == NULL)
        return 0;

    a = height(root->left);
    b = height(root->right);

    if(a > b)
        return a + 1;
    else
        return b + 1;
}

int count(struct node *root)
{
    if(root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

void display(struct node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int ch, x;

    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Height");
        printf("\n4.Total Nodes");
        printf("\n5.Display");
        printf("\n6.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 3:
                printf("Height = %d", height(root));
                break;

            case 4:
                printf("Total nodes = %d", count(root));
                break;

            case 5:
                printf("Tree: ");
                display(root);
                break;

            case 6:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    }while(ch != 6);

    return 0;
}
