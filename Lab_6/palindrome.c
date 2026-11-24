#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // 1. Find the middle of the linked list using slow and fast pointers
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half of the linked list
    struct Node* secondHalf = reverseList(slow->next);
    struct Node* copySecondHalf = secondHalf; // Keep reference to restore later

    // 3. Compare the first half and the reversed second half
    struct Node* firstHalf = head;
    bool palindrome = true;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // 4. Restore the original linked list structure (good practice)
    slow->next = reverseList(copySecondHalf);

    return palindrome;
}

// Helper function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating a palindrome linked list: 1 -> 2 -> 3 -> 2 -> 1
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Linked List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("Result: The linked list is a palindrome.\n");
    } else {
        printf("Result: The linked list is NOT a palindrome.\n");
    }

    return 0;
}
