#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; 
    struct node* next; 
};

struct node* createnode(int data){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
} 

struct node* insertatend(struct node* head,int data ){
    struct node* temp=head;
    struct node* newnode=createnode(data);
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;  
}

struct node* concatenate(struct node* head1, struct node* head2){
    if(head1 == NULL){
        head1 = head1; 
        return; 
    }

    struct node* temp = head1; 
    while(temp->next!=NULL){
        temp = temp->next; 
    }

    temp->next = head2; 
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head1 = NULL; 
    struct node* head2 = NULL; 

    insertatend(head1, 1); 
    insertatend(head1, 2);
    insertatend(head1, 3); 

    printf("First linked list: \n"); 
    printList(head1); 

    insertatend(head2, 5); 
    insertatend(head2, 6);
    insertatend(head2, 8); 

    printf("Second linked list: \n"); 
    printList(head2); 

    concatenate(head1, head2);

    printf("Concatenated linked list: "); 
    printList(head1); 
    return 0; 
}
