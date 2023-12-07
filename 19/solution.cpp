#include <stack>
vector<int> previousSmaller(vector<int> &arr, int n) {
    vector<int> prev(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            prev[i] = -1;
        } 
        else {
            prev[i] = s.top();
        }
        s.push(i);
    }
    return prev;
}
vector<int> nextSmaller(vector<int> &arr, int n) {
    stack<int> s;
    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            next[i] = n;
        } 
        else {
            next[i] = s.top();
        }
        s.push(i);
    }
    return next;
}
vector<int> maxMinWindow(vector<int> &arr, int n) {
    vector<int> answer(n, INT_MIN);
    vector<int> next = nextSmaller(arr, n);
    vector<int> prev = previousSmaller(arr, n);
    for (int i = 0; i < n; i++) {
        int length = next[i] - prev[i] - 1;
        answer[length - 1] = max(answer[length - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        answer[i] = max(answer[i], answer[i + 1]);
    }
    return answer;
}