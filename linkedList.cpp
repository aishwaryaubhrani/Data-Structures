
#include<stdio.h>
#include<stdlib.h>

//creating a node

struct node{
	int data;
	struct node *next;
};

struct node *head, *ptr;


//insertion at the beginning

void insert_beginning(){
	int item;
	struct node *ptr;
	
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	if(ptr == NULL){
		printf("\nOVERFLOW");
	}
	
	else{
		printf("\nEnter value to insert: ");
		scanf("%d", &item);
		ptr->data = item;
		ptr->next = head;
		head = ptr;	
		printf("\nInserted");
	}	
}

void last_insert(){
	int item;
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	if(ptr == NULL){
		printf("\nOVERLOW");
	}
	
	else{
		printf("\nEnter the value to insert: ");
		scanf("%d", &item);
		
		ptr->data = item;
		if(head == NULL){
			ptr->next = NULL;
			head = ptr;
			printf("\nInserted");
		}
				
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = ptr;
			ptr->next = NULL;
			printf("\nInserted");
		}
	}
}

void randomInsert(){
	printf("\nEnter the position for inserting: ");
	int position;
	scanf("%d", &position);
	
	int item;
	printf("\nEnter the number to insert: ");
	scanf("%d", &item);
	
	struct node *ptr, *temp;
	
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	if(ptr == NULL){
		printf("\nOVERFLOW");
	}
	
	else{
		ptr->data = item;
		temp = head;
		int i;
		for(i = 0; i<position; i++){
			temp = temp->next;
			if(temp == NULL){
				printf("\nCan't insert");
				return;
			}
		}
		ptr->next = temp->next;
		temp->next = ptr;printf("\nInserted");
	}
}

void delete_beginning(){
	struct node *ptr;
	if(head == NULL){
		printf("\nList is empty");
	}
	else{
		ptr = head;
		head = ptr->next;
		
		free(ptr);
		
		printf("\nDeleted");
	}
}

void delete_last(){
	struct node *ptr, *temp;
	
	if(head == NULL){
		printf("\nList is empty");
	}
	
	else if(head->next == NULL){
		free(head);
		printf("\nOnly one node deleted");
	}
	
	else{
		ptr = head;
		while(ptr->next != NULL){
			temp = ptr;
			ptr = ptr->next;
		}
	
		temp->next = NULL;
		free(ptr);
	}	
}

void randomDelete(){
	
	struct node *ptr, *temp;
	
	if(head == NULL){
		printf("\nList is empty");
	}
	
	else if(head->next == NULL){
		free(head);
		printf("\nOnly one node deleted");
	}
	
	else{
		int position;
		
		printf("\n Enter the position after which you want to delete: ");
		scanf("%d", &position);
		
		ptr = head;
		int loc;
		
		for(loc = 0; loc<position; loc++){
			temp = ptr;
			ptr= ptr->next;
			
			if(ptr == NULL){
				printf("\nCant delete");
				return;
			}
		}
		
		temp->next = ptr->next;
		free(ptr);
		
		printf("\nDeleted");
	}
}

void reverseIterate(){
	struct node *prev=NULL;
	struct node *current = head;
	struct node *next=NULL;
	
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	head = prev;
}

void printReverse(struct node *head){
	if(head == NULL){
		return;
	}
	
	printReverse(head->next);
	printf("%d", head->data);
}

void printList(){
	struct node *ptr;
	ptr = head;
	
	if(head == NULL){
		printf("Cannot print");
		return;
	}
	
	while(ptr != NULL){
		printf("%d ", ptr->data);
		
		ptr = ptr->next;
	}
}

int main(){
	int choice = 0;
	while(choice!=7){
		 printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Detete from beginning\n5.Delete from last\n6.Delete from any randrom position\n7.Reverse list\n8.Print reverse\n9.Print list");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        
        switch(choice){
        	case 1:  
            	insert_beginning();      
            	break;  
            case 2:  
            	last_insert();         
            	break;  
            case 3:  
            	randomInsert();  
				break;
			case 4:
				delete_beginning();
				break;
			case 5:
				delete_last();
				break;
			case 6:
				randomDelete();
				break;			  
			case 7:
				reverseIterate();
				break;
			case 8:
				printReverse(head);
				break;	
			case 9:
				printList();
				break;		
			case 10:
				exit(0);
				break;	
			default:
				printf("Please enter a valid choice");	   
		}
	}
}




















