/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int size_even = (numsSize+1)/2;
    int *ret_arr = (int *)malloc(sizeof(int) * numsSize);
    int ret_even_idx = 0;
    int ret_odd_idx = 1;
    int i = 0;
    while (i < numsSize) {
        // check odd part.
        if (nums[i] % 2 == 0) {
            ret_arr[ret_even_idx] = nums[i];
            ret_even_idx += 2;
        } else if (nums[i] % 2 == 1) {
            ret_arr[ret_odd_idx] = nums[i];
            ret_odd_idx += 2;
        }
        i++;
    }
    *returnSize = numsSize;
    return ret_arr;
}