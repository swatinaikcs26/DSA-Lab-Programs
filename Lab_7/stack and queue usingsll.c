#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

/* ---------------- STACK (LIFO) USING SLL ---------------- */
struct node* top = NULL;

void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack Overflow (Memory allocation failed)\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow (Stack is empty)\n");
        return;
    }
    struct node* temp = top;
    printf("Popped %d from stack\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("Stack (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------------- QUEUE (FIFO) USING SLL ---------------- */
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Queue Overflow (Memory allocation failed)\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued %d into queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow (Queue is empty)\n");
        return;
    }
    struct node* temp = front;
    printf("Dequeued %d from queue\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    printf("Queue (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Stack Operations ---\n");
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();

    printf("\n--- Queue Operations ---\n");
    enqueue(100);
    enqueue(200);
    enqueue(300);
    displayQueue();
    dequeue();
    displayQueue();

    return 0;
}
