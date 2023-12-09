vector<int> dirX = {0, 0, 1, -1};
vector<int> dirY = {1, -1, 0, 0};
bool isValid(vector<vector<int>> &mat, int x, int y, int dx, int dy){
    int n = mat.size();
    int m = mat[0].size();
    if (dx >= 0 && dx < n && dy >= 0 && dy < m && mat[dx][dy] > mat[x][y]){
        return true;
    }
    return false;
}
int dfs(vector<vector<int>> &mat, vector<vector<int>> &dp, int x, int y){
    if (dp[x][y] != 0){
        return dp[x][y];
    }
    int len = 1;
    for (int i = 0; i < 4; i++){
        int dx = x + dirX[i];
        int dy = y + dirY[i];
        if (isValid(mat, x, y, dx, dy)){
            int currLen = dfs(mat, dp, dx, dy) + 1;
            len = max(currLen, len);
        }
    }
    dp[x][y] = len;
    return len;
}
int longestIncreasingPath(vector<vector<int> > &mat, int n, int m){
    int maxLen = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            maxLen = max(dfs(mat, dp, i, j), maxLen);
        }
    }
    return maxLen;
}