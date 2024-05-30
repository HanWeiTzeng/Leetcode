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

void helper(struct Node* root, int* size_of_root, int *stack) {
    if (root == NULL) return;
    stack[*size_of_root] = root->val;
    *size_of_root += 1;
    for (int i = 0; i < root->numChildren; i++) {
        helper(root->children[i], size_of_root, stack);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int size_root = 0;
    int stack[10000];
    helper(root, &size_root, stack);
    *returnSize = size_root;
    int *ret_arr = (int *) malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < size_root; i++) {
        ret_arr[i] = stack[i];
    }
    return ret_arr;
}