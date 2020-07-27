#include<stdio.h>

void binarysearch(int arr[], int low, int high, int n){
	int mid = (high + low)/2;
	if(n == arr[mid]){
		printf("Number found at %d position", mid+1);
	}
	else if(n > arr[mid]){
		binarysearch(arr, mid+1, high, n);
	}
	else{
		binarysearch(arr, 0, mid-1, n);
	}
	
}


void main(){
	int arr[] = {1, 2, 5, 7, 14};
	int len = sizeof(arr)/sizeof(arr[0]);
	int n = 7;
	binarysearch(arr, 0, len-1, n);
}
