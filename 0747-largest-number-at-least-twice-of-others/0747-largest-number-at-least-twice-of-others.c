void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int dominantIndex(int* nums, int numsSize) {
    int key;

    for (int i = 0; i < 2; i++) {
        int max = nums[0];
        int idx = 0;
        for (int j = 1; j < numsSize-i; j++) {
            if (max < nums[j]) {
                max = nums[j];
                idx = j;
            }
        }
        swap(&nums[idx], &nums[numsSize-1-i]);
        if (i == 0) {
            key = idx;
        }
    }
    if (nums[numsSize-1] >= 2*nums[numsSize-2]) return key;
    else return -1;
}