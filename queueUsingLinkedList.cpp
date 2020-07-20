#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head;

void insert(){
	printf("\nEnter an item to insert");
	int item;
	scanf("%d", &item);
	
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	if(head == NULL){
		ptr->data = item;
		ptr->next = NULL;
		head = ptr;
	}
	
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		ptr->data = item;
		ptr->next = NULL;
		temp->next = ptr;
	}
	
	printf("\nInserted");
}

void deleteQ(){
	struct node *ptr;
	if(head == NULL){
		printf("\nNothing to delete");
		return;
	}
	else{
		if(head->next == NULL){
			head = NULL;
			free(head);
		}
		else{
			ptr = head;
			head = ptr->next;
			
			free(ptr);
		}
		
		printf("\nDeleted");
	}
}

void display(){
	struct node *ptr;
	ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

int main(){
	int choice;   
    while(choice != 4)   
    {     
        printf("\n*************************Main Menu*****************************\n"); 
        printf("\n=================================================================\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert();  
            break;  
            case 2:  
            deleteQ();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}
