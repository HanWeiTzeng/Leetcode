/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    // Handle root == NULL
    if (root == NULL) return NULL;
    // invert root->left and root->right
    invertTree(root->right);
    invertTree(root->left);
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}