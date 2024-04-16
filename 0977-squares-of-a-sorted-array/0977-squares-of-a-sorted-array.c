/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//  好幾種方法:

//  ================== Two pointer ==================
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ret_arr;
    ret_arr = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) nums[i] *= nums[i];
    int left = 0, right = numsSize-1;
    int len = numsSize - 1;
    while (left <= right && len >= 0) {
        if (nums[left] > nums[right]) {
            ret_arr[len--] = nums[left++];
        } else {
            ret_arr[len--] = nums[right--];
        }

    }
    return ret_arr;
}

/*
================== Quick Sort=====================

int cmp(const void* e1, const void* e2) {
    return *(int*)e1 - *(int*)e2;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ret_arr;
    ret_arr = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) ret_arr[i] = nums[i] * nums[i];
    qsort(ret_arr, numsSize, sizeof(int), cmp); 		//// sort here.
    return ret_arr;
}

==================Bubble Sort=====================

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ret_arr;
    ret_arr = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) nums[i] *= nums[i];
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    for (int i = 0; i < numsSize; i++) {
        ret_arr[i] = nums[i];
    }
    return ret_arr;
}
*/