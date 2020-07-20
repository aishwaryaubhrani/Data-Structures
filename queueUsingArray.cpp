#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5  


int front = -1, rear = -1;  
int queue[maxsize];  

void insert(){
	
	int item;
	printf("\nEnter the item: ");
	scanf("%d", &item);
	
	if(front>rear || rear>maxsize){
		printf("\nOVERFLOW");
		return;
	}
	else if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
	}
	
	else{
		rear+=1;
	}
	
	queue[rear] = item;
	printf("\nInserted");
}

void deleteQ(){
	if(front == -1 || front > rear){
		printf("\nNothing to delete");
		return;
	}
	
	else{
	
	if(front == rear){
		front = -1;
		rear = -1;
	}
	
	else{
		front += 1;
	}
	
	printf("\nDeleted");
}
}

void display(){
	int i;
	for(i = front; i<=rear; i++){
		printf("%d ", queue[i]);
	}
}

int main ()  
{  
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

