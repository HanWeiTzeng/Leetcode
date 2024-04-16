/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node, int value) {
    if (node == NULL) return 0;
    else {
        value += node->val;    
    }
    if (node->left != NULL && node->right != NULL) {
        value <<= 1;
        return dfs(node->left, value) + dfs(node->right, value);
    } else if (node->left == NULL && node->right != NULL) {
        return dfs(node->right, value);
    } else if (node->left != NULL && node->right == NULL) {
        return dfs(node->left, value);
    } else {
        return value;
    }
    
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0);
}