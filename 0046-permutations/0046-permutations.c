/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bfs(int* array, int end, int start, int **ret_2d_arr, int* returnSize, int** returnColumnSizes) {
// Function to generate all permutations of the array
    if (start == end - 1) {
        ret_2d_arr[*returnSize] = (int *) malloc(sizeof(int) * end);
        (*returnColumnSizes)[*returnSize] = end;
        for (int i = 0; i < end; i++) {
            ret_2d_arr[*returnSize][i] = array[i];
            printf("%d ", ret_2d_arr[*returnSize][i]);
        }
        printf("\n");
        *returnSize += 1;
    } else {
        for (int i = start; i < end; i++) {
            // Swap the current element with the start
            printf("array[start(%d)] = %d, array[i(%d)] = %d.\n", start, array[start], i, array[i]);
            swap(&array[start], &array[i]);
            // Recursively call permute for the remaining elements
            bfs(array, end, start + 1, ret_2d_arr, returnSize, returnColumnSizes);

            // Backtrack (restore the array to its original state)
            swap(&array[start], &array[i]);
        }
    }

}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // create numsSize pyramid size,
    int ret_size = 1;
    for (int i = 0; i < numsSize; i++) {
        ret_size *= (i+1);
    }
    int **ret_2d_arr = (int **) malloc(sizeof(int *) * ret_size);
    *returnColumnSizes = (int *)malloc(sizeof(int) * ret_size);
    *returnSize = 0;
    // algorithm
    bfs(nums, numsSize, 0, ret_2d_arr, returnSize, returnColumnSizes);

    return ret_2d_arr;
}