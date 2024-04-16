/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) return 0;
    int total = 0;
    if (root->val >= low && root->val <= high) {
        total += root->val;
        total += rangeSumBST(root->left, low, high);
        total += rangeSumBST(root->right, low, high);
    } else if (root->val < low) {
        total += rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
        total += rangeSumBST(root->left, low, high);
    }
    return total;
}