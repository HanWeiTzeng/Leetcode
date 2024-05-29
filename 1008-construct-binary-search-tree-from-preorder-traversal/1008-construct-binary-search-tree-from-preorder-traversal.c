/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    if (preorderSize <= 0) return NULL;
    // use first element to be root.
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int divide_idx = 1;
    while (divide_idx < preorderSize && preorder[divide_idx] < preorder[0]) {
        divide_idx++; // idx = 4:10
    }
    
    root->left = bstFromPreorder(preorder+1, divide_idx-1);
    root->right = bstFromPreorder(preorder+divide_idx, preorderSize-divide_idx);
    return root;
}