/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret_arr = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    // use 2 pointers i j to calculate sum
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ret_arr[0] = i;
                ret_arr[1] = j;
                return ret_arr;
            }
        }
    }
    return NULL;
}