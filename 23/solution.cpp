#include <deque>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k){
    deque<int> window(k);
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < k; i++){
        while ((!window.empty()) && nums[i] >= nums[window.back()]){
            window.pop_back();
        }
        window.push_back(i);
    }
    for (int i = k; i < n; i++){
        result.push_back(nums[window.front()]);
        while ((!window.empty()) && window.front() <= i - k){
            window.pop_front();
        }
        while ((!window.empty()) && nums[i] >= nums[window.back()]){
            window.pop_back();
        }
        window.push_back(i);
    }
    result.push_back(nums[window.front()]);
    return result;
}