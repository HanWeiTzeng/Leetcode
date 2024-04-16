/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
重點: 找到一樣的數字就跑看看是不是後面都一樣
如果是return true
不是的話，再把root->left 跟 root-> right帶進原式
再找一輪，再不是，再找。
*/

bool checkIfSame(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;
        else if (root == NULL && subRoot != NULL || root != NULL && subRoot == NULL) return false;
    if (root->val != subRoot->val) return false;
    return checkIfSame(root->left, subRoot->left) && checkIfSame(root->right, subRoot->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) return false;

    if (root->val == subRoot->val) {
        if (checkIfSame(root, subRoot)) return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}