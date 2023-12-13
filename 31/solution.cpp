vector<int> printRightView(BinaryTreeNode<int> *root){
    vector<int> ans;
    if (root == NULL){
        return {};
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        for (int i = 1; i <= n; i++){
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            if (i == n){
                ans.push_back(temp->data);
            }
            if (temp->left != NULL){
                q.push(temp->left);
            }
            if (temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    return ans;
}