long long maxSubarraySum(vector<int> arr, int n){
    long long maxSum = 0, curSum = 0;
    for(int i=0; i<n; i++){
        curSum = max(0ll, curSum + arr[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}