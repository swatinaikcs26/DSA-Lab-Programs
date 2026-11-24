#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(Node* head) {
    Node* curr = head;

    // Pick elements one by one
    while (curr != NULL && curr->next != NULL) {
        Node* runner = curr;

        // Compare the picked element with the rest of the elements
        while (runner->next != NULL) {
            if (curr->data == runner->next->data) {
                // Duplicate found: bypass and free it
                Node* dup = runner->next;
                runner->next = runner->next->next;
                free(dup);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating an unsorted list with duplicates: 10 -> 20 -> 10 -> 30 -> 20
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(20);

    printf("Original List: ");
    printList(head);

    removeDuplicates(head);

    printf("After Removing Duplicates: ");
    printList(head);

    return 0;
}
