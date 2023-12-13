int currentPathSum(BinaryTreeNode<int> *currentPeak, int &maxSum){
    if (currentPeak == NULL){
        return 0;
    }
    int maxPathSumLeft = max(currentPathSum(currentPeak->left, maxSum), 0);
    int maxPathSumRight = max(currentPathSum(currentPeak->right, maxSum), 0);
    int currentSum = maxPathSumLeft + maxPathSumRight + (currentPeak->data);
    maxSum = max(currentSum, maxSum);
    return max(maxPathSumLeft, maxPathSumRight) + (currentPeak->data);
}
int maxPathSum(BinaryTreeNode<int> *root){
    int maxSum = INT_MIN; 
    currentPathSum(root, maxSum);
    return maxSum;
}