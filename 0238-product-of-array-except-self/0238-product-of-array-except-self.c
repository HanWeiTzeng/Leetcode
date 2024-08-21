/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ret_val = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int count_left = 1;
    int count_right = 1;
    int count_total = 1;
    int j = 0, k = 0;
    int index_zero = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            index_zero = i;
        if (i > 0)
            count_right *= nums[i];
    }
    // with zero
    if (index_zero != -1) {
        for (int i = 0; i < numsSize; i++) {
            if (i != index_zero) {
                count_total *= nums[i];
                ret_val[i] = 0;
            }
        }
        ret_val[index_zero] = count_total;
        return ret_val;
    }

    // without zero
    for (int i = 0; i < numsSize; i++) {
        if (i > 0) {
            count_left *= nums[i-1];
            count_right /= nums[i];
        }
        count_total = count_left * count_right; // 
        ret_val[i] = count_total;
    }
    return ret_val;
}