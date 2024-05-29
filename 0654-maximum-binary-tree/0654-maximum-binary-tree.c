/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if (numsSize <= 0) return NULL;

    // find largest in array.
    int root_val = -1;
    int max_idx = -1;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (root_val < nums[i]) {
            root_val = nums[i];
            max_idx = i;
        }
    }
    //printf("%d max_idx = %d\n", root_val, max_idx);
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    // divide left array and right array
    // put them into next recursive loop by link root->left and root->right.
    root->left = constructMaximumBinaryTree(nums, max_idx);
    root->right = constructMaximumBinaryTree(nums+max_idx+1, numsSize-max_idx-1);
    return root;
}