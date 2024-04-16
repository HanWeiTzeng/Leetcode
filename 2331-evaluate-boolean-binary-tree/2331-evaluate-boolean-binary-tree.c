/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    // leaf node
    if (root->left == NULL && root->right == NULL) {
        if (root->val == 1) {
            return true;
        } else if (root->val == 0) {
            return false;
        }
    } else {    //if (root->left == NULL) {
        bool a = evaluateTree(root->left);
        bool b = evaluateTree(root->right);
        if (root->val == 2) {
            return a | b;
        } else if (root->val == 3) {
            return a & b;
        }
    }
    return 0;
}