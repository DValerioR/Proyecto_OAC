#include <stdlib.h>
#include <stdio.h>

typedef struct NodeStruct{
    int data;
    struct NodeStruct *next;
}Node;


typedef struct StructQueue ;
{
    Node *front;
    Node *back;
    int size;
} *Queue;

Queue createQueue(){
    Queue newQueue=malloc(sizeof(Queue));
    newQueue->front=NULL;
    newQueue->back=NULL;   
    newQueue->size=0;
    return newQueue;
}

void enQueue(Queue q,int value){
    Node * newNode=malloc(sizeof(Node));
    newNode->next=NULL;
    if(q->size!=0)
    q->back->next=newNode;
    else{
        q->front=newNode;
    }
    q->back=newNode;
    newNode->data=value;
    q->size++;
}

int* deQueue(Queue q){
    if(q->size==0){
        return NULL;
    }
    Node* temp=q->front;
    int* data=malloc(sizeof(int));
    *data=temp->data;
    q->front=q->front->next;
    free(temp);
    q->size--;
    return data;
}