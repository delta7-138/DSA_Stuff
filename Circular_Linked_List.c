#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *addatbeg(struct Node **head , int data){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
	return temp;
}
struct Node *addatend(struct Node **head , int data){
	if(*head==NULL){
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = temp;
		*head = temp;
	}
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	struct Node *mv = *head;
	while(mv->next!=*head){
		mv = mv->next;
	}
	mv->next = temp;
	temp->data = data;
	temp->next = *head;
}
int main(){
	int n, inp;
	scanf("%d" , &n);
	
	struct Node *head = NULL;
	for(int i = 0; i<n; i++){
		scanf("%d" , &inp);
		addatend(&head , inp);
	}
	struct Node *temp = head;
	for(int i = 0; i<n; i++){
		printf("%d\n" , temp->data);
		temp = temp->next;
	}

	return 0;
}


