#include<stdio.h>

/*time complexity
best case: O(1)
average case: O(n)
worst case: O(n)
*/

void linearsearch(int arr[], int len, int n){
	int i;
	for(i = 0; i<len; i++){
		if(arr[i] == n){
			printf("Number found at position %d", i+1);
		}
	}
}

void main(){
	int arr[] = {1, 2, 5, 7, 14, 16};
	int len = sizeof(arr)/sizeof(arr[0]);
	int n = 14;
	linearsearch(arr, len, n);
}
