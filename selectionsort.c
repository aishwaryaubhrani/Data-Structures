#include<stdio.h>

//In selection sort we place the minimum number at first place in the array.
//Best case, Average case and Worst case time complexities are O(n^2).

void selectionsort(int arr[], int len){
	int i, j, temp, min, min_index;
	for(i = 0; i<len-1; i++){
		min = arr[i];
		min_index = i;
		for(j = i; j<len; j++){
			if(arr[j] <= min){
				min = arr[j];
				min_index = j;
			}
		}
		
		//swapping the min number and the number at index i
		temp = arr[i];
		arr[i] = min;
		arr[min_index] = temp;
	}
	
	//printing sorted array
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
}



void main(){
	int arr[] = {10,30, 5, 20, 35, 55};
	int len = sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr, len);
}
