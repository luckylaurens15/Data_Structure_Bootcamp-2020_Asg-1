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

// Remove Duplicate Element From Sorted Linked List

void remove (Node *curr){
    Node *beforecurr =head;
    Node *aftercurr = curr->next;
    while (beforecurr->next != curr){
        beforecurr= beforecurr->next;
    }
    beforecurr->next = aftercurr;
    free(curr);
}

void duplicate (){
    Node *curr = head;
    while (curr && curr != tail){
        if (curr->score == curr->next->score){
            if (curr==head){
                popHead ();
            }else{
                remove (curr);
            }
        }
        curr = curr->next;
    }
}

int main (){
    pushHead (1); 
    pushTail (2); 
    pushTail (3);
    pushTail (3); 
    pushTail (3);
    pushTail (4);
    pushTail (4);
    pushTail (5);
    pushTail (5);
    printf ("Sorted Linked List          : "); printLinkedList();
    duplicate ();
    printf ("After Remove The Ducplicate : "); printLinkedList();
    return 0;
}