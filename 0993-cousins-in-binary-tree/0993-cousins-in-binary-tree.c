/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /*
int dfs(struct TreeNode* root, int value) {
    if (root == NULL) return 0;
    int k = 1;
    if (root->val == value) {
        return k;
    }
    if (root->val != value && root->left != NULL) {
        return k + dfs(root->left, value);
    }
}
*/
void store_node(struct TreeNode* root, int arr[][2], int *idx, int depth) {
    if (root == NULL) return;
    arr[*idx][0] = root->val;
    arr[*idx][1] = depth;
    //(*idx)++;
    store_node(root->left, arr, idx, depth+1);
    store_node(root->right, arr, idx, depth+1);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    int arr[100][2], idx = 0, depth = 0;
    store_node(root, arr, &idx, depth);
    int depth_x = 0, depth_y = 0;
    for (int i = 0; i < idx; i++) {
        if (x == arr[i][0]) {
            depth_x = arr[i][1];
            printf("depth_x = %d, depth_y = %d", depth_x, depth_y);
        } else if (y == arr[i][0]) {
            depth_y = arr[i][1];
            
        }
    }
    printf("depth_x = %d, depth_y = %d", depth_x, depth_y);
    if (depth_x == depth_y) return true;
    else return false;   // i = 0
}