/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #define MAX(A,B) ((A) > (B)? (A) : B)

int helper(struct TreeNode* root, int* ans) {
    if (!root) return 0;

    int left = helper(root->left, ans);
    int right = helper(root->right, ans);
    *ans = MAX(*ans, left + right + 1);
    return MAX(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    helper(root, &ans);
    return ans-1;
}