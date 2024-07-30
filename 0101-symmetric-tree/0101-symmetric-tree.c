/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check_Symmetric(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return true;
    if (left != NULL && right == NULL || left == NULL && right != NULL) return false;
    if (left->val == right->val) {
        return check_Symmetric(left->right, right->left) & check_Symmetric(left->left, right->right);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    return check_Symmetric(root->left, root->right);
}