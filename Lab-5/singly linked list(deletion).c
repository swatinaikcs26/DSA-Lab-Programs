#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert at end to create the linked list
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
}

// 1. Delete from beginning
void deleteFromFirst(struct Node **head)
{
    struct Node *temp;

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = temp->next;

    free(temp);

    printf("Node deleted from beginning\n");
}

// 2. Delete from end
void deleteFromEnd(struct Node **head)
{
    struct Node *temp, *prev;

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted from end\n");
}

// 3. Delete from specified position
void deleteAtPosition(struct Node **head, int position)
{
    struct Node *temp, *del;
    int i;

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(position == 1)
    {
        deleteFromFirst(head);
        return;
    }

    temp = *head;

    for(i = 1; i < position-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;

    free(del);

    printf("Node deleted from position %d\n", position);
}

// Display the linked list
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
    int n, value, choice, position, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);

        insertAtEnd(&head, value);
    }

    while(1)
    {
        printf("\n\n1. Delete at beginning");
        printf("\n2. Delete at end");
        printf("\n3. Delete at position");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                deleteFromFirst(&head);
                break;

            case 2:
                deleteFromEnd(&head);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
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
