/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int subfunction(struct TreeNode* root, int *max) {
    if (root == NULL) return 0;

    int left_length = subfunction(root->left, max);
    int right_length = subfunction(root->right, max);
    int total_length_tmp = left_length + right_length;
    *max = fmax(*max, total_length_tmp);

    return (left_length > right_length ? left_length : right_length) + 1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int max = 0;
    subfunction(root, &max);
    return max;
}