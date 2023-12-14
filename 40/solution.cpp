#include <algorithm>
int longestIncreasingSubsequence(int arr[], int n){
    int dp[n];
    int ans = 0;
    for (int i = 0; i < n; i++){
        int position = lower_bound(dp, dp + ans, arr[i]) - dp;
        dp[position] = arr[i];
        if (position == ans){
            ans++;
        }
    }
    return ans;
}