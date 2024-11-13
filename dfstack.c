#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node{
    int vertex; 
    struct Node* next; 
};

struct Graph{
    int graphVertices;
    struct Node** adjLists; 
    int* visited; 
};

struct Stack{
    int items[MAX]; 
    int top; 
};

struct Node* createnode(int v){
    struct Node* newnode = malloc(sizeof(struct Node)); 
    newnode->vertex = v; 
    newnode->next = NULL; 
    return newnode; 
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph)); 
    graph->graphVertices = vertices; 

    graph->adjLists = malloc(vertices * (sizeof(struct Node*))); 
    graph->visited = malloc(vertices * (sizeof(int))); 

    for(int i=0; i<vertices; i++){
        graph->adjLists[i] = NULL; 
        graph->visited[i] = 0; 
    }
    return graph; 
}

struct Stack* createStack(){
    struct Stack* stack = malloc(sizeof(struct Stack)); 
    stack->top = -1; 
    return stack; 
}

int isEmpty(struct Stack* stack){
    return stack->top == -1; 
}

void push(struct Stack* stack, int value){
    if(stack->top < MAX-1){
        stack->items[++stack->top] = value; 
    }
}

int pop(struct Stack* stack){
    if(!isEmpty(stack)){
        return stack->items[stack->top--];
    }
    return -1; 
}

void addEdge(struct Graph* graph, int src, int dest){
    struct Node* newnode = createnode(dest); 
    newnode->next = graph->adjLists[src]; 
    graph->adjLists[src] = newnode; 

    newnode = createnode(src); 
    newnode->next = graph->adjLists[dest]; 
    graph->adjLists[dest] = newnode; 
}

void DFS(struct Graph* graph, int startVertex) {
    struct Stack* stack = createStack();
    push(stack, startVertex);
    graph->visited[startVertex] = 1;

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                push(stack, adjVertex);
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}
