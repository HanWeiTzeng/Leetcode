/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root, int value) {
    bool check_flag = 1;
    // left part.
    if (root->val < value) {
        if (root->left != NULL) {
            if (root->left->val < value) {
                check_flag &= dfs(root->left, value);
            } else {
                return false;
            }
        }
        if (root->right != NULL) {
            if (root->right->val < value) {
                check_flag &= dfs(root->right, value);
            } else {
                return false;
            }
        }
        return check_flag;
    } else {
    // right part.
        if (root->left != NULL) {
            if (root->left->val > value) {
                check_flag &= dfs(root->left, value);
            } else {
                return false;
            }
        }
        if (root->right != NULL) {
            if (root->right->val > value) {
                check_flag &= dfs(root->right, value);
            } else {
                return false;
            }
        }
        return check_flag;
    }
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL || root->left == NULL && root->right == NULL) return true;

    bool check_right = 0;
    bool check_left = 0;
    if (root->right != NULL) {
        if (root->right->val <= root->val) {
            return false;
        } else {
            if (dfs(root->right, root->val) == false) return false;
            // check if the rest of right node still bigger than root->val. 
        }
    }
    if (root->left != NULL) {
        if (root->left->val >= root->val) {
            return false;
        } else {
            if (dfs(root->left, root->val) == false) return false;
        }
    }
    return isValidBST(root->right) && isValidBST(root->left);
}