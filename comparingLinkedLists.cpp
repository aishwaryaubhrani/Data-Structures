#include<stdio.h>
#include<stdlib.h>

struct node1{
	int data;
	struct node1 *next;
};

struct node1 *head;

void push(int element){
	struct node1 *ptr, *temp;
	ptr = (struct node1 *)malloc(sizeof(struct node1 *));
	ptr->data = element;


	if(head == NULL){
		ptr->next = head;
		head = ptr;
	}
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = NULL;
	}
}

struct node2{
	int data2;
	struct node2 *next2;
};

struct node2 *head2;

void push2(int element){
	struct node2 *ptr, *temp;
	ptr = (struct node2 *)malloc(sizeof(struct node2 *));
	ptr->data2 = element;

	if(head2 == NULL){
		ptr->next2 = head2;
		head2 = ptr;
	}
	else{
		temp = head2;
		while(temp->next2 != NULL){
			temp = temp->next2;
		}
		temp->next2 = ptr;
		ptr->next2 = NULL;
	}
}

void compare(){
	struct node1 *ptr1;
	struct node2 *ptr2;
	
	ptr1 = (struct node1 *)malloc(sizeof(struct node *));
	ptr2 = (struct node2 *)malloc(sizeof(struct node2 *));
	
	ptr1 = head;
	ptr2 = head2;
	
	int flag = 0;
	
	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1->next != NULL && ptr2->next2 == NULL){
			flag = 0;
		}
		
		else if(ptr1->next == NULL && ptr2->next2 !=NULL){
			flag = 0;
		}
		else if(ptr1->data == ptr2->data2){
			flag = 1;
		}
		else{
			flag = 0;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next2;
		
	}
	printf("%d\n", flag);
}

int main(){
	int testcases;
	scanf("%d", &testcases);
	int i;
	
	for(i = 0; i<testcases; i++){
		int numberOfElementsFirstList;
		scanf("%d", &numberOfElementsFirstList);
		int j;
		for(j = 0; j<numberOfElementsFirstList; j++){
			int element;
			scanf("%d", &element);
			push(element);
		}
		
		int numberOfElementsSecondList;
		scanf("%d", &numberOfElementsSecondList);
		
		int k;
		for(k = 0; k<numberOfElementsSecondList; k++){
			int element;
			scanf("%d", &element);
			push2(element);
		}
		
		compare();
		
	}
}
