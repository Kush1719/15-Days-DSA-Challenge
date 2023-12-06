#include <algorithm>
long long pairsWithGivenSum(int arr[], int n, int sum){
    long long ans = 0;
    sort(arr, arr + n);
    long long i = 0, j = n - 1;
    while (i < j){
        if (arr[i] + arr[j] < sum){
            i++;
        }
        else if (arr[i] + arr[j] > sum){
            j--;
        }
        else{
            long long initialLeftElement = arr[i], initialLeftIndex = i;
            while (i < j && arr[i] == initialLeftElement){
                i++;
            }
            long long initialRightElement = arr[j], initialRightIndex = j;
            while (j >= i && arr[j] == initialRightElement){
                j--;
            }
            if (initialLeftElement == initialRightElement){
                long long equalNumbers = (i - initialLeftIndex) + (initialRightIndex - j) - 1;
                ans += (equalNumbers * (equalNumbers + 1)) / 2;
            }
            else{
                ans += ((i - initialLeftIndex) * (initialRightIndex - j));
            }
        }
    }
    return ans;
}