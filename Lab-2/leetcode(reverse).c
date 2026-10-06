#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX] = "abcdef";
    char target;
    int i = 0;
    int target_found = 0;

    printf("Original string: %s\n", str);
    printf("Enter character to reverse up to: ");
    scanf(" %c", &target);

    // Step 1: Scan the string to check if target exists
    for (int k = 0; str[k] != '\0'; k++) {
        if (str[k] == target) {
            target_found = 1;
            break;
        }
    }

    if (!target_found) {
        printf("Character not found in string! Output: %s\n", str);
        return 0;
    }

    // Step 2: Push elements onto stack until the target character is reached
    while (str[i] != '\0') {
        push(str[i]);
        if (str[i] == target) {
            i++;
            break;
        }
        i++;
    }

    // Step 3: Pop from stack to reverse the first part of the string
    int j = 0;
    while (top != -1) {
        str[j++] = pop();
    }

    printf("Result: %s\n", str);

    return 0;
}
