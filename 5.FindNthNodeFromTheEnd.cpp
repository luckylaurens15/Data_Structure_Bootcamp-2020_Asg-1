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

// Find The Nth Node From The End Of Linked List
void find (int x){
    Node *temp = head;
    int count =0;
    while (temp){
        count++;
        temp = temp->next;
    }
    int N = count - x + 1;
    Node *curr= head;
    printf ("Node %d from the end of Linked List : ", x);
    while (curr){
        N--;
        if (N==0){
            printf("%d\n", curr->score);
        }
        curr = curr->next;
   }
}

int main (){
    pushHead (95); 
    pushTail (97); 
    pushHead (100);
    pushHead (98); 
    pushTail (120);
    printf ("Linked List                        : "); printLinkedList();
    find (2);
    find (4);
    find (3);
    return 0;
}