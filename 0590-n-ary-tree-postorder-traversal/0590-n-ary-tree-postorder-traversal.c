/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int count(struct Node* root) {
    if (root == NULL) return 0;
    int sum = 0;
    for (int i = 0; i < root->numChildren; i++) {
        sum += count(root->children[i]);
    }
    return 1 + sum;
}

void helper(struct Node* root, int* size_of_root, int *stack) {
    if (root == NULL) return;
    for (int i = 0; i < root->numChildren; i++) {
        helper(root->children[i], size_of_root, stack);
    }
    stack[*size_of_root] = root->val;
    *size_of_root += 1;
}
int* postorder(struct Node* root, int* returnSize) {
    int sum = count(root);
    int size_root = 0;
    int *ret_arr = (int *) malloc(sizeof(int) * sum);
    helper(root, &size_root, ret_arr);
    *returnSize = size_root;
    return ret_arr;
}

