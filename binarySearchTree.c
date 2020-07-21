#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *deleteNode(struct node *ptr, int item){
	if(ptr == NULL){
		return ptr;
	}
	
	if(item < ptr->data){
		ptr->left = deleteNode(ptr->left, item);
	}
	else if(item > ptr->data){
		ptr->right = deleteNode(ptr->right, item);
	}
	else{
		if(ptr->left == NULL){
			struct node *temp = ptr->right;
			free(ptr);
			return temp;
		}
		
		else if(ptr->right == NULL){
			struct node *temp = ptr->left;
			free(ptr);
			return temp;
		}
	
		//if there are two child nodes we have to get inorder successor
		struct node *ptr1 = ptr->right;
		while(ptr1->left !=NULL){
			ptr1 = ptr1->left;
		}
		
		ptr->data = ptr1->data;
        ptr->right = deleteNode(ptr->right, ptr1->data); 
	}
	
	return ptr;
}


struct node *search(struct node *ptr, int item){
	if(ptr == NULL){
		printf("\nCant find\n");
		return ptr;
	}
	
	if(item == ptr->data){
		printf("\nFound");
		return ptr;
	}
	
	else if(item > ptr->data){
		return search(ptr->right, item);
	}
	
	else{
		return search(ptr->left, item);
	}	
}

struct node *insert(struct node *ptr, int item){
	if(ptr == NULL){
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
	}
	
	if(item < ptr->data){
		ptr->left = insert(ptr->left, item);
	}
	
	else if(item > ptr->data){
		ptr->right = insert(ptr->right, item);
	}
	
	return ptr;
}

void inorder(struct node *root){
	if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
}

int main(){
	struct node *root = NULL;
	struct node *temp = NULL;
    root = insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    
    inorder(root);
    
    search(root, 7);
    
    root = deleteNode(root, 1);
    
    inorder(root);
}
