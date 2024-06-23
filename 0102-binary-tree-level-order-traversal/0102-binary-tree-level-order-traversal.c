/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void helper(struct TreeNode* root, int* returnSize, int** returnColumnSizes, int level, int** ret_mat) {
    if (root == NULL) {
        return;
    }
    if (level >= *returnSize) {
        *returnSize = level + 1;
    }
    //deal with level 0
    if ((*returnColumnSizes)[level] == 0) {
        ret_mat[level] = (int *)malloc(2000 * sizeof(int));
    }
    ret_mat[level][(*returnColumnSizes)[level]++] = root->val;
    helper(root->left, returnSize, returnColumnSizes, level+1, ret_mat);
    helper(root->right, returnSize, returnColumnSizes, level+1, ret_mat);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        returnColumnSizes = NULL;
        return NULL;
    }
    int** ret_mat = (int **)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int *)calloc(2000, sizeof(int));
    int level = 0;
    helper(root, returnSize, returnColumnSizes, level, ret_mat);
    return ret_mat;
}