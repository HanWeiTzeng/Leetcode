/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool check_if_mirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return true;
    else if (left != NULL && right == NULL) return false;
    else if (left == NULL && right != NULL) return false;
    
    if (left->val == right->val) {
        return (check_if_mirror(left->left, right->right) && check_if_mirror(left->right, right->left));
    } else {
        return false;
    }
 }
bool isSymmetric(struct TreeNode* root) {
    return check_if_mirror(root->left, root->right);
}