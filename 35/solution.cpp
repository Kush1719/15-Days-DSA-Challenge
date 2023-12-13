vector<int> nextPermutation(vector<int> &permutation, int n){
    for (int i = n - 2; i >= 0; i--){
        if (permutation[i] < permutation[i + 1]){
            int id = n - 1;
            for (int j = i + 1; j < n; j++){
                if (permutation[j] < permutation[i]){
                    id = j - 1;
                    break;
                }
            }
            swap(permutation[i], permutation[id]);
            for (int j = 0; j < (n - i) / 2; j++){
                swap(permutation[i + 1 + j], permutation[n - 1 - j]);
            }
            return permutation;
        }
    }
    for (int i = 0; i < n; i++){
        permutation[i] = i + 1;
    }
    return permutation;
}