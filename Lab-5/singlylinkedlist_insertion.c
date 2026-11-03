#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// 1. Insert at beginning
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = value;
    newnode->next = *head;

    *head = newnode;

    printf("Node inserted at beginning\n");
}

// 2. Insert at end
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = value;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    printf("Node inserted at end\n");
}

// 3. Insert at specified position
void insertAtPosition(struct Node **head, int value, int position)
{
    struct Node *newnode, *temp;
    int i;

    if(position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    temp = *head;

    for(i = 1; i < position-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = value;
    newnode->next = temp->next;

    temp->next = newnode;

    printf("Node inserted at position %d\n", position);
}

// Display function
void display(struct Node *head)
{
    struct Node *temp = head;

    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice, value, position;

    while(1)
    {
        printf("\n\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertAtPosition(&head, value, position);
                break;

            case 4:
                display(head);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
