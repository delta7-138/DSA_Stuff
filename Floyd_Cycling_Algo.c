#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *push(struct Node **head , int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
    return temp;
}
void traverse_list(struct Node *head){
    while(head!=NULL){
        printf("%d-->" , head->data);
        head = head->next;
    }printf("NULL\n");
}
int check_straight_or_not(struct Node *head){
    struct Node *p1 = head;
    struct Node *p2 = head;
    while(p2!=NULL){
        p1 = p1->next;
        p2 = p2->next;
        if(p2!=NULL){
            p2 = p2->next;
        }else{
            //printf("in else 1");
            return 0;
        }
        if(p1==p2){
            //printf("in if 1");
            return 1;
        }
    }//printf("%p" , p2);
    //printf("hel\n");
    return 0;
}
int main(){
    int num_str, inp;
    scanf("%d" , &num_str);

    int num_curve;
    scanf("%d" , &num_curve);

    //Creation of straight linked list 
    struct Node *str_head = NULL;
    for(int i = 0; i<num_str; i++){
        scanf("%d"  , &inp);
        push(&str_head , inp);
    }

    //Creation of circular linked list
    struct Node *curve_head = NULL;
    for(int i = 0; i<num_curve; i++){
        scanf("%d" , &inp);
        push(&curve_head , inp);
    }

    struct Node *temp = curve_head;
    for(int i = 0; i<4; i++){
        temp = temp->next;
    }

    struct Node *temp_2 = curve_head;
    while(temp_2->next!=NULL){
        temp_2 = temp_2->next;
    }
    temp_2->next = temp;

    //traverse_list(curve_head);
    int ans_1 = check_straight_or_not(str_head);
    int ans_2 = check_straight_or_not(curve_head);
    
    printf("%d %d" ,ans_1 , ans_2);
    return 0;

}