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
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;
    return (left > right)? left : right; 
}

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
    *returnSize = maxDepth(root);
    int** ret_mat = (int **)malloc(sizeof(int*) * *returnSize);
    *returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
    *returnSize = 0;
    helper(root, returnSize, returnColumnSizes, 0, ret_mat);
    return ret_mat;
}