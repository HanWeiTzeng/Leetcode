/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) {
        return true;
    } else if (root->left != NULL && root->right != NULL) {
        if (root->left->val == root->val && root->right->val == root->val) {
            return isUnivalTree(root->left) && isUnivalTree(root->right);
        } else {
            return false;
        }
    } else if (root->left != NULL) {
        if (root->left->val == root->val) {
            return isUnivalTree(root->left);
        } else {
            return false;
        }
    } else if (root->right != NULL) {
        if (root->right->val == root->val) {
            return isUnivalTree(root->right);
        } else {
            return false;
        }
    }
    return true;
}