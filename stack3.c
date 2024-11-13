#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5  // Define a maximum stack size

struct Node {
    int data;
    struct Node* next;
};

// Push function
void push(struct Node** top, int data, int* count) {
    // Check if stack is full
    if (*count >= MAX_STACK_SIZE) {
        printf("Stack is full. Cannot push %d\n", data);
        return;
    }
    
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Heap Overflow.\n");
        return;
    }

    newnode->data = data;
    newnode->next = *top; // Point to the current top
    *top = newnode; // Update top
    (*count)++; // Increment element count
    printf("%d pushed to the stack\n", data);
}

// Check if the stack is empty
int isEmpty(struct Node* top) {
    return !top;
}

// Pop function
int pop(struct Node** top, int* count) {
    if (isEmpty(*top)) {
        printf("Stack underflow.\n");
        return -1;
    }

    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    (*count)--; // Decrement element count
    return popped;
}

// Peek function
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Display the stack elements
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to return the number of elements in the stack
int stackSize(int count) {
    return count;
}

int main() {
    struct Node* top = NULL;
    int count = 0;  // Counter for number of elements in the stack

    push(&top, 10, &count);  // Pass count by reference
    push(&top, 20, &count);
    push(&top, 30, &count);
    push(&top, 40, &count);
    push(&top, 50, &count);

    // Try to push when stack is full
    push(&top, 60, &count);

    display(top);

    printf("Stack size: %d\n", stackSize(count));  // Show the number of elements

    printf("%d popped from stack\n", pop(&top, &count));
    display(top);

    printf("Top element is %d\n", peek(top));

    printf("Stack size: %d\n", stackSize(count));  // Show updated stack size

    return 0;
}
