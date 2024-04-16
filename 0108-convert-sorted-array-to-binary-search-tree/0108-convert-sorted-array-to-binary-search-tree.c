/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//  想清楚為什麼right是這樣寫: (The rest of array) // think !!!!

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) return NULL;

    int middle = numsSize/2;
    struct TreeNode* node = NULL;
    node = malloc(sizeof(struct TreeNode));
    node->val = nums[middle];
    node->left = sortedArrayToBST(nums, middle);
    node->right = sortedArrayToBST(nums+middle + 1, numsSize - middle - 1);
    return node;
}
/*
===================================

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return NULL;

    int mid = numsSize/2; // 上界

    struct TreeNode* Node;
    Node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    Node->val = nums[mid];
    Node->left = sortedArrayToBST(nums, mid);
    Node->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);  // think !!!!

    return Node;
}
*/
