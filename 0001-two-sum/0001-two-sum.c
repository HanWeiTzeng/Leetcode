/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret_arr = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    // use 2 pointers i j to calculate sum
    int i = 0, j = 1;
    while (i < numsSize) {
        while (j < numsSize) {
            if (nums[i] + nums[j] != target) {
                j++;
            } else {
                ret_arr[0] = i;
                ret_arr[1] = j;
                return ret_arr;
            }
        }
        i++;
        j = i+1;
    }
    return NULL;
}