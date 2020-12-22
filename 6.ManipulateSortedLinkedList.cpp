#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name [255];
    int score;
    Node *next;
} *head, *tail, *head2, *tail2;

Node *createNode (int score){
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode -> score = score;
    newNode-> next = NULL;
    return newNode;
}

// ASCENDING LL

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

// DESCENDING LL

void pushHead2 (int score){
    Node *temp = createNode (score);

    if (!head2){
        head2 = tail2 = temp;
    }
    else {
        temp->next =  head2;
        head2 = temp;
    }
}

void pushTail2 (int score){
    Node *temp = createNode (score);

    if (!head2){ 
        head2= tail2 = temp; 
    }
    else { 
        tail2->next = temp;
        tail2 =  temp;
    }
}

void popHead2 (){
    if (!head2){
        return;
    } else if (head2==tail2) {
        head2 = tail2 = NULL;
        free(head2);
    }
    else {
        Node *temp = head2; 
        head2 = temp->next; 
        temp->next = NULL; 
        free(temp); 
    }
}

void popTail2 (){
    if (!head2){
        return;
    }
    else if (head2==tail2){
        head2 = tail2 = NULL;
        free(head2);
    }
    else {
        Node *temp = head2; 
        while (temp->next != tail2){
            temp = temp->next;
        }              
        temp->next = NULL; 
        free(tail2); 
        tail2 = temp;
    }
}

void printLinkedList2 (){
    Node *curr = head2;

    while (curr){
        printf("%d -> ", curr->score);
        curr = curr->next;
    }
    printf ("NULL\n");
}

// Manipulate From Ascending To Descending

void manipulate (){
    Node *curr = tail;
    Node *beforecurr = head;
    while (beforecurr->next != curr){
        beforecurr= beforecurr->next;
    }
    int stop = 1;
    while (stop){
        pushTail2 (curr->score);
        curr = beforecurr;
        
        if (curr!= head){
            beforecurr = head;
            while (beforecurr->next != curr){
                beforecurr= beforecurr->next;
            }
        }
        if (curr == head){
            pushTail2 (curr->score);
            stop = 0;
        }
    }
}

int main (){
    pushHead (1); 
    pushTail (2); 
    pushTail (3);
    pushTail (3); 
    pushTail (4);
    pushTail (5);
    pushTail (5);
    pushTail (6);
    pushTail (8);
    printf ("Sorted Ascending Linked List  : "); printLinkedList();
    manipulate ();
    printf ("Sorted Descending Linked List : "); printLinkedList2();
    return 0;
}