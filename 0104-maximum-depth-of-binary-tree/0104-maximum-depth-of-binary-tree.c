/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int subfunction(struct TreeNode* root, int level) {
    if (root == NULL) {
        return level;
    }

    int left_deep = subfunction(root->left, level + 1);     // 9
    int right_deep = subfunction(root->right, level + 1);

    return (left_deep > right_deep) ? left_deep : right_deep;
}
int maxDepth(struct TreeNode* root) {
    int level = 0;
    int ret_val = subfunction(root, level);
    return ret_val;
}