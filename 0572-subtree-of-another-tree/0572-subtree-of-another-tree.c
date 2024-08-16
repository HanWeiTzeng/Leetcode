/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;
    if (root == NULL ||subRoot == NULL) return false;
    if (root->val == subRoot->val) {
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
    return false;
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;
    if (root == NULL ||subRoot == NULL) return false;
    if (root->val == subRoot->val) {
        bool check = isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        if (check) return true; 
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}