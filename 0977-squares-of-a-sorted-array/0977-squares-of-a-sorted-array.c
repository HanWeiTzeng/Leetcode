/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ret_arr = (int *)malloc(sizeof(int)* numsSize);
    int index_min = 0;
    int min_val = nums[0] * nums[0];

    *returnSize = numsSize;

    // square all elements in array and record the min value and it index.
    for (int i = 0; i < numsSize; i++) {
        nums[i] *= nums[i];
        if (min_val > nums[i]) {
            min_val = nums[i];
            index_min = i;
        }
    }
    int index_left = index_min - 1;
    int index_right = index_min + 1;
    // rearrange them by 2 index(pointer).
    // while (index_left >= 0 && index_right < numsSize)
    int index = 0;
    ret_arr[index++] = nums[index_min];

    while (index_left >= 0 && index_right < numsSize) {
        if (nums[index_left] < nums[index_right]) {
            ret_arr[index++] = nums[index_left--];
        } else {
            ret_arr[index++] = nums[index_right++];
        }
    }

    // deal with the rest of index_left >= 0 "or" index_right < numsSize
    while (index_left >= 0) {
        ret_arr[index++] = nums[index_left--];
    }
    while (index_right < numsSize) {
        ret_arr[index++] = nums[index_right++];
    }

    // return allocated array.
    return ret_arr;
}