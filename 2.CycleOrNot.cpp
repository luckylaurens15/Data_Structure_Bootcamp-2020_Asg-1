#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name [255];
    int score;
    int cycle=0;
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

// Determining Cycle Or Not
void cycleornot (){
    Node *curr = head;

    while (curr && curr->cycle<=1){
        curr->cycle++;
        curr = curr->next;
    }
    Node *curr1 = head;
    int valid=0;
    while (curr1){
        if (curr1->cycle > 1){
            printf("This Linked List has Cycle\n");
            valid=1;
            break;
        }
        curr1 = curr1->next;
    }
    if (valid==0) printf("This Linked List has no Cycle\n");
}

int main (){
    pushHead (95); 
    pushTail (97); 
    pushHead (100);
    pushHead (98); 
    printLinkedList();
    cycleornot ();
    return 0;
}