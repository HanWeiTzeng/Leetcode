/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
// 注意邊界 edge situation. 
// if (root == NULL) return root;


struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *tmp;
    if (root == NULL) return root;
    // invert 1st layer of tree.
    if (root->left != NULL || root->right != NULL) {
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    // recursive next layer.
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}