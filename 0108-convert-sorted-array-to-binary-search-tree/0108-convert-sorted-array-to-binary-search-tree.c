/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // deal with the input nums[]
    if (numsSize <= 0) return NULL;
    // start from middle = numsSize/2;
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    int middle = numsSize/2;
    root->val = nums[middle];
    // then put the left part at root->left.
    root->left = sortedArrayToBST(nums, middle);
    // put the right part at root->right.
    root->right = sortedArrayToBST(nums+middle+1, numsSize-middle-1);
    // return root.
    return root;
}