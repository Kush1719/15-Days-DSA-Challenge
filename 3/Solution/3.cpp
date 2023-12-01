#include<bits/stdc++.h>
vector<int> maximumsumSubarray(vector<int> &arr , int n){
    	int maxSum = INT_MIN;
	int start = 0;
	int end = -1;
	for( int i = 0; i < n; i++){
		int localSum = 0;
		for( int j = i; j < n; j++){
			localSum = localSum + arr[j];
			if ( localSum > maxSum ){
				maxSum = localSum;
				start = i;
				end = j;
			}
			else if( localSum == maxSum ){
				if( end-start < j - i ){
					start = i;
					end = j;
				}
			}
		}
	}
	vector<int> ans;
	for(int i = start; i <= end; i++){
		ans.push_back(arr[i]);
	}
	return ans;
}