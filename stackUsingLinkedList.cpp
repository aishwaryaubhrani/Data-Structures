#include<stdio.h>
#include<stdlib.h>

struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
  
void push(){
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	
	int item;
	printf("\nEnter val: ");
	scanf("%d", &item);
	
	if(head == NULL){
		ptr->val = item;
		head = ptr;
		ptr->next = NULL;
	}
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		ptr->val = item;
		ptr->next = NULL;
		temp->next = ptr;
	}
	
	printf("\nPushed");
}  

void pop(){
	struct node *ptr, *temp;
	ptr = head;
	while(ptr->next != NULL){
		temp = ptr;
		ptr = ptr->next;
	}
	temp->next = NULL;
	free(ptr);
	printf("\nPopped");
}

void display(){
	struct node *ptr;
	ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
}
  
int main ()  
{  
    int choice=0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  
}  
