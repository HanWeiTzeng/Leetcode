/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count_nodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int insert_node_into_array(struct TreeNode* root, int* array, int index) {
    if (root == NULL)
        return index;
    if (root->left != NULL) {
        index = insert_node_into_array(root->left, array, index);
    }
    array[(index)++] = root->val;
    // printf("index = %d, array[] = %d\n", index-1, array[index-1]);
    if (root->right != NULL) {
        index = insert_node_into_array(root->right, array, index);
    }
    return index;
}
void mergeSortedArray(int* ret_arr, int* array_1, int* array_2, int len_1, int len_2) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < len_1 && j < len_2) {
        if (array_1[i] < array_2[j]) {
            ret_arr[k] = array_1[i];
            k++;
            i++;
        } else {
            ret_arr[k] = array_2[j];
            k++;
            j++;
        }
    }
    while (i < len_1) {
        ret_arr[k] = array_1[i];
        k++;
        i++;
    }
    while (j < len_2) {
        ret_arr[k] = array_2[j];
        k++;
        j++;
    }
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2,
int* returnSize) {
    // create 2 array for putting value in root1, and root2
    int count_1 = count_nodes(root1);
    int count_2 = count_nodes(root2);
    // merge these 2 sorted array by merging sort way.
    int* array_1 = malloc(sizeof(int) * count_1);
    int* array_2 = malloc(sizeof(int) * count_2);
    insert_node_into_array(root1, array_1, 0);
    insert_node_into_array(root2, array_2, 0);
    int* ret_arr = (int*)malloc(sizeof(int) * (count_1 + count_2));
    mergeSortedArray(ret_arr, array_1, array_2, count_1, count_2);
    *returnSize = count_1 + count_2;
    // return it.
    free(array_1);
    free(array_2);
    return ret_arr;
}