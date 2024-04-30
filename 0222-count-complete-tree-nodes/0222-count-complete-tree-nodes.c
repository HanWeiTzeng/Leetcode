/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes_extra(struct TreeNode* root, int *total_nodes) {
    if (root == NULL) return 0;
    else {
        *total_nodes += 1;
        countNodes_extra(root->left, total_nodes);
        countNodes_extra(root->right, total_nodes);
        return *total_nodes;
    }
}

int countNodes(struct TreeNode* root) {
    int total_nodes = 0;
    countNodes_extra(root, &total_nodes);
    return total_nodes;
}