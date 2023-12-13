double median(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()){
        swap(a, b);
    }
    int n = a.size(), m = b.size();
    int low = 0, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        int part = (n + m + 1) / 2 - mid;
        if (part > m){
            low = mid + 1;
            continue;
        }
        int leftMax = 0, rightMin = 1e9 + 1;
        if (mid > 0){
            leftMax = max(leftMax, a[mid - 1]);
        }
        if (part > 0){
            leftMax = max(leftMax, b[part - 1]);
        }
        if (mid < n){
            rightMin = min(rightMin, a[mid]);
        }
        if (part < m){
            rightMin = min(rightMin, b[part]);
        }
        if (leftMax <= rightMin){
            if ((n + m) & 1){
                return leftMax;
            }
            return (leftMax + rightMin) / 2.0;
        }
        if (a[mid] < leftMax){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}