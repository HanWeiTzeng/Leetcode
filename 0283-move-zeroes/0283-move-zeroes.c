void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize) {
    int left = 0, right = 0;
    // detect 0 and use swap to switch
    while (right < numsSize) {
        if (nums[right] != 0) {
            if (left != right) {
                swap(nums+left, nums+right);
            }
            left++;
        }
        right++;
    }
}