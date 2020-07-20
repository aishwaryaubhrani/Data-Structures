#include<stdio.h>
#include<stdlib.h>

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  

void beginsert(){
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	printf("\nEnter the item to insert: ");
	int item;
	scanf("%d", &item);
	
	if(head == NULL){
		ptr->data = item;
		head = ptr;
		ptr->next = head;
	}	
	else{
		ptr->data = item;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = head;
		head = ptr;
	}
	
	printf("\nInserted");
}

void lastinsert(){
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	printf("\nEnter the item to insert: ");
	int item;
	scanf("%d", &item);
	
	if(head == NULL){
		head = ptr;
		ptr->next = head;
	}
	else{
	while(temp->next != head){
		temp = temp->next;
	}
	
	temp->next = ptr;
	ptr->next = head;
}
	printf("\nInserted");
	
}

void begin_delete(){
	struct node *ptr;
	if(head->next == head){
		head = NULL;
		free(head);
	}
	else{
		ptr = head;
		while(ptr->next != head){
			ptr = ptr->next;
		}
		
		ptr->next = head->next;
		free(head);
		head = ptr->next;
	}
	
	printf("\nDeleted");
}

void last_delete(){
	struct node *ptr, *temp;
	ptr = head;
	while(ptr->next != head){
		temp = ptr;
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	free(ptr);
	printf("\nDeleted");
}

void main ()  
{  
    int choice =0;  
    while(choice != 7)   
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            begin_delete();       
            break;  
            case 4:  
            last_delete();        
            break;  
            case 5:  
            search();         
            break;  
            case 6:  
            display();        
            break;  
            case 7:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
