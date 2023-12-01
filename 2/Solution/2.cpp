#include<bits/stdc++.h>
int findMajorityElement(int arr[], int n){
	int majorityElement = -1;
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(count == 0) {
			majorityElement = arr[i];
			count = 1;
			continue;
		}
		if(arr[i] == majorityElement){
			count++;
		}		
		else {
			count--;
		}
	}
	count = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == majorityElement){
			count++;
		}
	}
	if(count > n / 2){
		return majorityElement;
	}
	return -1;	
}