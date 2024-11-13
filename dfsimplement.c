#include <stdio.h>
#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void DFS(int start, int n) {
    int i;
    push(start);
    visited[start] = 1;
    
    while (top != -1) {
        int node = pop();
        printf("%d ", node + 1);

        for (i = 0; i < n; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, start;
    char choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter 1 if %d has a node with %d else 0: ", i + 1, j + 1);
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("The adjacency matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    do {
        for (i = 0; i < n; i++)
            visited[i] = 0;  // Reset visited array for each DFS call

        printf("Enter the source vertex: ");
        scanf("%d", &start);
        printf("DFS Traversal starting from vertex %d: ", start);
        DFS(start - 1, n);

        printf("\nDo you want to continue (Y/N)? ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
