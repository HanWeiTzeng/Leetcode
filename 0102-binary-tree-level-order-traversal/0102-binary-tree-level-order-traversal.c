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

void addnum(int size, int **ret_mat, int val, int level) {
    ret_mat[level] = realloc(ret_mat[level], size * sizeof(int));
    ret_mat[level][size-1] = val;
}

void helper(struct TreeNode* root, int** returnColumnSizes, int level, int** ret_mat) {
    if (root == NULL) {
        return;
    }
    (*returnColumnSizes)[level]++;
    addnum((*returnColumnSizes)[level], ret_mat, root->val, level);
    level++;
    helper(root->left, returnColumnSizes, level, ret_mat);
    helper(root->right, returnColumnSizes, level, ret_mat);
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }
    // Find max depth for setting *returnSize & ret_mat & *returnColumnSizes
    int depth = maxDepth(root);
    *returnSize = depth;
    int** ret_mat = calloc(depth, sizeof (int *));
    *returnColumnSizes = (int *)calloc(depth, sizeof(int));
    helper(root, returnColumnSizes, 0, ret_mat);
    return ret_mat;
}