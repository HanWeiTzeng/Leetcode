/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    if (root == p || root == q) {
        return root;
    }
    struct TreeNode* Ansleft = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* Ansright = lowestCommonAncestor(root->right, p, q);
    if (Ansright != NULL && Ansleft != NULL) {
        return root;
    } else if (Ansright != NULL && Ansleft == NULL) {
        return Ansright;
    } else if (Ansleft != NULL && Ansright == NULL) {
        return Ansleft;
    } else return NULL;
}
