#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return head;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct node* head) {
    struct node *i, *j;
    int t;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

struct node* reverse(struct node* head) {
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node* con(struct node* head1, struct node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    struct node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    printf("--- Create List 1 ---\n");
    struct node* head1 = create(3);

    printf("\n--- Create List 2 ---\n");
    struct node* head2 = create(2);

    printf("\nList 1: ");
    display(head1);

    sort(head1);
    printf("Sorted List 1: ");
    display(head1);

    head1 = reverse(head1);
    printf("Reversed List 1: ");
    display(head1);

    head1 = con(head1, head2);
    printf("Concatenated List (1 + 2): ");
    display(head1);

    return 0;
}
