#include<stdio.h>
#include<stdlib.h>

void maxSubarrayProduct(int arr[]){
	int maxProduct = arr[0];
	int imax = arr[0];
	int imin = arr[0];
	int temp, i;
	for(i= 1; i<5; i++){
		if(arr[i] < 0){
			temp = imax;
			imax = imin;
			imin = temp;
		}
		if(imax >= imax*arr[i]){
			imax = imax;
		}
		else{
			imax = imax*arr[i];
		}
		
		if(imin <= imin*arr[i]){
			imin = imin;
		}
		else{
			imin = imin*arr[i];
		}
		
		if(maxProduct<=imax){
			maxProduct = imax;
		}
	}
	
	printf("\nMax product is: %d", maxProduct);
	}

int main(){
	int arr[] = {1, 2, -1, 3, 1};
	
	maxSubarrayProduct(arr);
}
