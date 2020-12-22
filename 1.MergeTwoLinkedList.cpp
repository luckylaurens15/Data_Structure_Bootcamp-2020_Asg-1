#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node1 {
    int score;
    Node1 *next; // pointer ke node selanjutnya
} *head1, *tail1, *head2, *tail2, *headm, *tailm; // head node pertama, tail terakhir

Node1 *createNode1 (int score){
    Node1 *newNode = (Node1*) malloc (sizeof(Node1));
    newNode -> score = score;
    newNode-> next = NULL;
    return newNode;
}

// NODE KE 1

void pushHead1 (int score){
    Node1 *temp = createNode1 (score); // buat node nya

    if (!head1){ // linked list kosong
        head1 = tail1 = temp; // temp akan menjadi head dan tail
    }
    else { // >= 1 node
        temp->next =  head1;
        head1 = temp;
    }
}

void pushTail1 (int score){
    Node1 *temp = createNode1 (score);

    if (!head1){ // linked list kosong
        head1= tail1 = temp; // temp akan menjadi head dan tail
    }
    else { // >= 1 node
        tail1->next = temp;
        tail1 =  temp;
    }
}

void popHead1 (){
    if (!head1){
        return;
    } else if (head1==tail1) {
        head1 = tail1 = NULL;
        free(head1);
    }
    else {
        Node1 *temp = head1; // 99 (head, temp) -> 100 -> 96 -> 98 (tail)
        head1 = temp->next; // 99 (temp) -> 100 (head) -> 96 -> 98 (tail)
        temp->next = NULL; // 99 (temp) -> NULL || 100 (head) -> 96 -> 98 (tail)
        free(temp); // 100 (head) -> 96 -> 98 (tail)
    }
}

void popTail1 (){
    if (!head1){
        return;
    }
    else if (head1==tail1){
        head1 = tail1 = NULL;
        free(head1);
    }
    else {
        Node1 *temp = head1; // 99 (temp, head) -> 100 -> 96 -> 98 (tail)
        while (temp->next != tail1){
            temp = temp->next;
        }              // 99 (head) -> 100 -> 96 (temp) -> 98 (tail)
        temp->next = NULL; // 99 (head) -> 100 -> 96 (temp) -> NULL (tail)
        free(tail1); // 99 (head) -> 100 -> 96 (temp) -> NULL
        tail1 = temp; //  99 (head) -> 100 -> 96 (temp, tail) -> NULL
    }
}

void printLinkedList1 (){
    Node1 *curr = head1; // curr adalah index yang akan berjalan

    while (curr){ // selama curr tidak sama dengan NULL
        printf("%d -> ", curr->score);
        curr = curr->next; // Update curr nya ke next
    }
    printf ("NULL\n");
}

// NODE KE 2

void pushHead2 (int score){
    Node1 *temp = createNode1 (score); // buat node nya

    if (!head2){ // linked list kosong
        head2 = tail2 = temp; // temp akan menjadi head dan tail
    }
    else { // >= 1 node
        temp->next =  head2;
        head2 = temp;
    }
}

void pushTail2 (int score){
    Node1 *temp = createNode1 (score);

    if (!head2){ // linked list kosong
        head2= tail2 = temp; // temp akan menjadi head dan tail
    }
    else { // >= 1 node
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
        Node1 *temp = head2; // 99 (head, temp) -> 100 -> 96 -> 98 (tail)
        head2 = temp->next; // 99 (temp) -> 100 (head) -> 96 -> 98 (tail)
        temp->next = NULL; // 99 (temp) -> NULL || 100 (head) -> 96 -> 98 (tail)
        free(temp); // 100 (head) -> 96 -> 98 (tail)
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
        Node1 *temp = head2; // 99 (temp, head) -> 100 -> 96 -> 98 (tail)
        while (temp->next != tail2){
            temp = temp->next;
        }              // 99 (head) -> 100 -> 96 (temp) -> 98 (tail)
        temp->next = NULL; // 99 (head) -> 100 -> 96 (temp) -> NULL (tail)
        free(tail2); // 99 (head) -> 100 -> 96 (temp) -> NULL
        tail2 = temp; //  99 (head) -> 100 -> 96 (temp, tail) -> NULL
    }
}

void printLinkedList2 (){
    Node1 *curr = head2; // curr adalah index yang akan berjalan

    while (curr){ // selama curr tidak sama dengan NULL
        printf("%d -> ", curr->score);
        curr = curr->next; // Update curr nya ke next
    }
    printf ("NULL\n");
}

// CREATE LINKED LIST FOR MERGE

void pushTailm (int score){
    Node1 *temp = createNode1 (score);

    if (!headm){ // linked list kosong
        headm= tailm = temp; // temp akan menjadi head dan tail
    }
    else { // >= 1 node
        tailm->next = temp;
        tailm =  temp;
    }
}

void merge (){
    Node1 *templeft = head1;
    Node1 *tempright = head2;
    while (templeft && tempright){
        if (templeft->score < tempright->score){
            pushTailm(templeft->score);
            templeft=templeft->next;
        }else {
            pushTailm(tempright->score);
            tempright= tempright->next;
        }
    }
    while (templeft){
        pushTailm(templeft->score);
        templeft=templeft->next;
    }
    while (tempright){
        pushTailm(tempright->score);
        tempright= tempright->next;
    }
}

void printLinkedListm (){
    Node1 *curr = headm; // curr adalah index yang akan berjalan

    while (curr){ // selama curr tidak sama dengan NULL
        printf("%d -> ", curr->score);
        curr = curr->next; // Update curr nya ke next
    }
    printf ("NULL\n");
}

int main (){
    pushHead1 (1);
    pushTail1 (4);
    pushTail1 (6);
    printf ("L1 = "); printLinkedList1();
    pushHead2 (2);
    pushTail2 (3);
    pushTail2 (5);
    printf("L2 = "); printLinkedList2();
    merge ();
    printf("Merge = "); printLinkedListm();
    return 0;
}