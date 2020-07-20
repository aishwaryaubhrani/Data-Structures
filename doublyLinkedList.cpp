#include<stdio.h>
#include<stdlib.h>

//program for doubly linked list

struct node{
	struct node *prev;
	struct node *next;
	int data;
};

struct node *head;

void insertion_beginning(){
	int item;
	
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	printf("\nEnter the element to insert: ");
	scanf("%d", &item);
	
	if(head == NULL){
	ptr->next = NULL;
	ptr->prev = NULL;
	}
	
	else{
	ptr->next = head;
	ptr->prev = NULL;
	head->prev = ptr;
	}
	
	ptr->data = item;
	head = ptr;
	
	printf("\nInserted");
}

void insertion_last(){
	int item;
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	printf("\nEnter the element to insert: ");
	scanf("%d", &item);
	
	if(head == NULL){
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->data = item;
		head = ptr;
	}
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		ptr->data = item;
		temp->next = ptr;
		ptr->prev = temp;
		ptr->next = NULL;
	}
	
	printf("\nInserted");

}

void deletion_beginning(){
	struct node *ptr;
	if(head == NULL){
		printf("\nNothing to delete");
		return;
	}
	else{
		if(head == NULL){
			head == NULL;
			free(head);
			printf("\nDeleted");
		}
		else{
			ptr = head;
			head = head->next;
			head->prev = NULL;
			free(ptr);
			printf("\nDeleted");
		}
	}
}

void deletion_last(){
	struct node *ptr;
	
	if(head->next == NULL){
		head = NULL;
		free(head);
		printf("\nDeleted");
	}
	
	else{
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->prev->next = NULL;
		free(ptr);
		printf("\nDeleted");
	}
}

void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  
        5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
            insertion_last();  
            break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
