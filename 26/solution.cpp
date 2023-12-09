#include <algorithm>
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++){
        int curS = intervals[i][0];
        int curE = intervals[i][1];
        if (res.size() == 0 || curS > res[res.size() - 1][1]) {
            res.push_back(intervals[i]);
        }
        else {
            res[res.size() - 1][1] = max(res[res.size() - 1][1], curE);
        }
    }
    return res;
}