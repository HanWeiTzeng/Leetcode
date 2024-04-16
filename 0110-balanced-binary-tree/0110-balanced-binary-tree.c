/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count_branch(struct TreeNode* root) {
    int count_num = 0;
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return 1;
    else {
        int cr = count_branch(root->right);
        int cl = count_branch(root->left);

        if (cr < 0 || cl < 0 || fabs(cr - cl) > 1)
        return -1;
        count_num += 1 + fmax(cl, cr);
    }
    return count_num;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    if (count_branch(root) >= 0) return true;
    else return false;
}
/* 力扣官方题解
===========================



bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    } else {
        return fabs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
}
*/