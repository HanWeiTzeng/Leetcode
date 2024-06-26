/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//  注意初始值 if root == NULL 是return 0不是1

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    int maxd = 1 + fmax(maxDepth(root->left), maxDepth(root->right));
    return maxd;
}

/*
===========================

int maxDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}


作者：力扣官方题解
链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/349250/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/