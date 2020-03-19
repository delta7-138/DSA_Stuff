#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000

//Function to enqueue
int enqueue(int queue[] , int *tail , int x){
    queue[++(*tail)] = x;
}

//Function to dequeue
int dequeue(int queue[] , int *head){
    *head = *head + 1;
    return queue[*head - 1];
}

//Function to print queue
void traverse_queue(int queue[] , int head , int tail){
    for(int i = head; i<=tail; i++){
        printf("%d " , queue[i]);
    }printf("\n");
}

int main(){
    int queue[LARGE];
    int n;

    printf("Enter initial size of the queue : \n");
    scanf("%d" , &n);

    int head = 0 , tail = n-1;
    for(int i = 0; i<n; i++){
        scanf("%d" , &queue[i]);
    }

    int num_op ,op ,data;
    printf("Enter number of operations : \n");
    scanf("%d" , &num_op);
    for(int i = 0; i<num_op; i++){
        printf("Enter the option : ");
        printf("1. enqueue\n");
        printf("2. dequeue\n");

        scanf("%d" , &op);

        switch(op){
            case 1:
            scanf("%d" , &data);
            enqueue(queue , &tail , data);
            break;

            case 2:
            dequeue(queue , &head);
            break;

            default:
            traverse_queue(queue , head , tail);
        }
        traverse_queue(queue , head , tail);
    }
    return 0;
}   