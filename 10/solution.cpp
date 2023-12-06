#include<cstring>
int maximalAreaOfSubMatrixOfAll1(vector < vector < int > > & mat, int n, int m) {
    if (mat.empty()) return 0;
    int left[m];
    int right[m];
    int height[m];
    fill_n(left, m, 0);
    fill_n(right, m, m);
    fill_n(height, m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int curLeft = 0;
        int curRight = m;
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                left[j] = max(left[j], curLeft);
            } else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            if (mat[i][j] == 1) {
                right[j] = min(right[j], curRight);
            } else {
                right[j] = m;
                curRight = j;
            }
        }
        for (int j = 0; j < m; j++) {
            maxArea = max(maxArea, height[j] * (right[j] - left[j]));
        }
    }
    return maxArea;
}