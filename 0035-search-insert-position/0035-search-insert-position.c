int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[0] >= target) return 0;
        if (nums[i] >= target) return i;
    }
    return 0;
}