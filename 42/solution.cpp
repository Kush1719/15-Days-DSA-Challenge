#include <vector>
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<bool>> vis;
void getTotalIslandsHelper(int** mat, int n, int m, int x, int y){
    if(!(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y])){
        return;
    }
    vis[x][y] = true;
    for(int i=0; i<8; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        getTotalIslandsHelper(mat, n, m, nextX, nextY);
    }
}
int getTotalIslands(int** mat, int n, int m){
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    int islands = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1 && !vis[i][j]){
                islands++;
                getTotalIslandsHelper(mat, n, m, i, j);
            }
        }
    }
    return islands;
}