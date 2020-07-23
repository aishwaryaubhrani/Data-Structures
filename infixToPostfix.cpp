#include<stdio.h>
#include<stdlib.h>
#include <string.h> 


struct stack{
	int data;
	struct stack *next;
};

struct stack *head;

void push(char ch){
	struct stack *ptr, *temp;
	ptr = (struct stack *)malloc(sizeof(struct stack *));
	
	if(head == NULL){
		ptr->data = ch;
		ptr->next = NULL;
		head = ptr;	
	}
	else{
		ptr->data = ch;
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = ptr;
		ptr->next = NULL;
	}
}

char peek(){
	struct stack *ptr;
	ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	
	return ptr->data;
}

void pop(){
	struct stack *ptr, *temp;
	ptr = head;
	if(head == NULL){
		return;
	}
	else if(head->next == NULL){
		head = NULL;
		free(head);
		return;
	}
	else{
		while(ptr->next != NULL){
			temp = ptr;
			ptr = ptr->next;
		}
		
		temp->next = NULL;
		free(ptr);
	}
}

int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 

void infixToPostfix(char exp[]){
	int i;
	for(i = 0; i<strlen(exp); i++){
		if(isOperand(exp[i])){
			printf("%c", exp[i]);
		}
		else if(exp[i] == '('){
			push(exp[i]);
		}
		
		else if(exp[i] == ')'){
			while (head!=NULL && peek() != '('){
				printf("%c", peek());
				pop();
			} 
			if(head!=NULL && peek()!='('){
				return;
			}
			else{
				pop();
			}
		}
		
		else{
			while (head!=NULL && precedence(exp[i]) <= precedence(peek())) {
				printf("%c", peek());
                pop();
            }
            push(exp[i]); 
		}
	}
	
	struct stack *temp;
	temp = head;
	while(temp != NULL){
		printf("%c", temp->data);
		temp = temp->next;
	}
}

int main(){
 	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}
