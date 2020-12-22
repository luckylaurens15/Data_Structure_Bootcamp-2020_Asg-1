#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name [255];
    int score;
    Node *next;
} *head, *tail;

Node *createNode (int score){
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode -> score = score;
    newNode-> next = NULL;
    return newNode;
}

void pushHead (int score){
    Node *temp = createNode (score);

    if (!head){ 
        head = tail = temp; 
    }
    else {
        temp->next =  head;
        head = temp;
    }
}

void pushTail ( int score){
    Node *temp = createNode (score);

    if (!head){ 
        head= tail = temp; 
    }
    else {
        tail->next = temp;
        tail =  temp;
    }
}

void popHead (){
    if (!head){
        return;
    } else if (head==tail) {
        head = tail = NULL;
        free(head);
    }
    else {
        Node *temp = head; 
        head = temp->next; 
        temp->next = NULL; 
        free(temp); 
    }
}

void popTail (){
    if (!head){
        return;
    }
    else if (head==tail){
        head = tail = NULL;
        free(head);
    }
    else {
        Node *temp = head; 
        while (temp->next != tail){
            temp = temp->next;
        }           
        temp->next = NULL;
        free(tail);
        tail = temp; 
    }
}

void printLinkedList (){
    Node *curr = head;

    while (curr){ // selama curr tidak sama dengan NULL
        printf("%d -> ", curr->score);
        curr = curr->next;
    }
    printf ("NULL\n");
}

// Determining Middle Element
void middle (){
    Node *curr = head;
    int count=0;
    while (curr){
        count++;
        curr= curr->next;
    }
    int mid = count/2;
    Node *curr1 = head;
    while (mid>0){
        curr1= curr1->next;
        mid--;
        if (mid==0){
            printf("Middle Element : %d\n", curr1->score);
        }
    }
}


int main (){
    pushHead (95); 
    pushTail (97); 
    pushHead (100);
    pushHead (98); 
    pushTail (120);
    printLinkedList();
    middle();
    return 0;
}