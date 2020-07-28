#include<stdio.h>

//In insertion sort we traverse the array in reverse manner from the key position and place the minimum number first.
// Best case time complexity will be O(n) when the array is already sorted.
//Average and Worst case time complexities are O(n^2).


void insertionsort(int arr[], int len){
	int i, j, key;
	for(i = 1; i<len; i++){
		j = i-1;
		key = arr[i];
		while(j >= 0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
	
	//printing the sorted array
	for(i = 0; i<len; i++){
		printf("%d ", arr[i]);
	}
}

void main(){
	int arr[] = {10,30, 5, 20, 35, 55};
	int len = sizeof(arr)/sizeof(arr[0]);
	insertionsort(arr, len);
}
