/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    *returnSize = heightsSize;
    int n = heightsSize;
    int *ret_arr = (int *) malloc(sizeof(int) * n);
    int *stack = (int *) malloc(sizeof(int) * n);
    int stackSize = 0;
    for (int i = n-1; i >= 0; i--) {
        ret_arr[i] = 0;
        while (stackSize > 0 && stack[stackSize-1] <= heights[i]) {
            stackSize--;
            ret_arr[i]++;
        }
        if (stackSize > 0) {
            ret_arr[i]++;
        }
        stack[stackSize++] = heights[i];
    }

    return ret_arr;
}