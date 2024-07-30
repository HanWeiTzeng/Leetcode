int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    while (i < numsSize-1) {
        if (nums[i] != nums[i+1]) {
            return nums[i];
        }
        i += 2;
    }
    return nums[numsSize-1];
}