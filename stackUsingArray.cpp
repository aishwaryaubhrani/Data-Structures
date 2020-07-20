#include<stdio.h>
#include<stdlib.h>

//stack implementation using array

int stack[100],i,j,choice=0,n,top=-1;  


void push(){
	printf("\nEnter an element to push: ");
	int item;
	scanf("%d", &item);
	
	if(top == n){
		printf("\nOVERFLOW");
	}
	else{
		top += 1;
		stack[top] = item;
		printf("\nPushed");
	}
}

void pop(){
	if(top == -1){
		printf("\nUNDERFLOW");
	}
	else{
		top -= 1;
	}
}

void show(){
	for(i = 0; i<=top; i++){
		printf("%d ", stack[i]);
	}
	
	if(top == -1){
		printf("\nStack is empty");
	}
}



int main ()  
{  
      
    printf("\nEnter the number of elements in the stack ");   
    scanf("%d",&n);  
    printf("*********Stack operations using array*********");  
  
printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\nChose one from the below options...\n");  
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
                show();  
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
