/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sub_isBalanced(struct TreeNode* root, int depth) {
    if (root == NULL) return depth;
    if (root->left == NULL && root->right == NULL) return depth+1;
    // else 
    int left = sub_isBalanced(root->left, depth+1);
    int right = sub_isBalanced(root->right, depth+1);
    
    if (abs(left - right) > 1 || left == -1 || right == -1) {
        return -1;
    }
    return fmax(left, right);
}

bool isBalanced(struct TreeNode* root) {
    int depth = 0;
    if (root == NULL) return true;
    //int left = sub_isBalanced(root->left, depth+1);
    //int right = sub_isBalanced(root->right, depth+1);
    // need to add depth of root in function.
    if (sub_isBalanced(root, depth) != -1) {
        return true;
    }
    return false;

}