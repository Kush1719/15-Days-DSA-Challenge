#include <string.h>
string longestPalinSubstring(string str){
    int n = str.length();
    if (n < 1) {
        return "";
    }
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int maxLength = 1;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i+1]) {
            dp[i][i + 1] = true;
            if(maxLength < 2){
                start = i;
                maxLength = 2;
            }
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (dp[i + 1][j - 1] && str[i] == str[j]) {
                dp[i][j] = true;
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }

        }
    }
    return str.substr(start, maxLength);
}