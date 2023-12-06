#include <queue>
#include <climits>
class Cell{
public:
    int cost;
    int i;
    int j;
    Cell(int cost, int i, int j) : cost(cost), i(i), j(j){
    }
};
int isValid(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}
int minCostToDestination(int **matrix, int n, int m, int x, int y){
    if (matrix[x][y] == 0)
        return -1;
    int **minCost, i, j, k, curCost, nextI, nextJ, newCost;
    minCost = new int *[n];
    for (i = 0; i < n; i++){
        minCost[i] = new int[m];
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
        {
            minCost[i][j] = INT_MAX;
        }
    }
    deque<Cell> dq;
    dq.push_front(Cell(0, 0, 0));
    minCost[0][0] = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    vector<pair<int, int>> ans;
    while (!dq.empty()){
        Cell minCostCell = dq.front();
        dq.pop_front();
        i = minCostCell.i;
        j = minCostCell.j;
        curCost = minCostCell.cost;
        if (i == x && j == y){
            break;
        }
        for (k = 0; k < 4; k++){
            nextI = i + dx[k];
            nextJ = j + dy[k];
            if (isValid(nextI, nextJ, n, m) && matrix[nextI][nextJ] == 1){
                if (k < 2){
                    newCost = curCost;
                    if (minCost[nextI][nextJ] > newCost){
                        minCost[nextI][nextJ] = newCost;
                        dq.push_front(Cell(newCost, nextI, nextJ));
                    }
                }
                else{
                    newCost = curCost + 1;
                    if (minCost[nextI][nextJ] > newCost){
                        minCost[nextI][nextJ] = newCost;
                        dq.push_back(Cell(newCost, nextI, nextJ));
                    }
                }
            }
        }
    }
    curCost = minCost[x][y];
    for (i = 0; i < n; ++i){
        delete[] minCost[i];
    }
    delete[] minCost;
    if (curCost == INT_MAX)
        return -1;
    return curCost;
}