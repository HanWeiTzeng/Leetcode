/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    *returnSize = heightsSize;
    int *ret_arr = (int *) malloc(sizeof(int) * heightsSize);
    int idx_ret_arr = 0;
    while (idx_ret_arr < heightsSize) {
        int block_height = 0;
        ret_arr[idx_ret_arr] = 0;
        for (int i = idx_ret_arr+1; i < heightsSize; i++) {
            if (block_height < heights[i]) {
                if (heights[idx_ret_arr] > block_height)
                ret_arr[idx_ret_arr]++;
                block_height = heights[i];
            }
            if (block_height >= heights[idx_ret_arr]) break;
        }
        idx_ret_arr++;
    }
    return ret_arr;
}