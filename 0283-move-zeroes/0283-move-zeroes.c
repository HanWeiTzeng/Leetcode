//  1. 移動零:
//  2. 直接後面補零:

void swap (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize) {
    int left = 0, right = 0;
    while (right < numsSize) {
        if (nums[right] != 0) {                                 // 右指標 不等於零才做
            if (left != right)
            swap(nums + left, nums + right);
            left++;
        }
        right++;                                                         // 右指標 去找不是零的
    }
}

//  ============================
//  2. 直接補零:
/*
void moveZeroes(int* nums, int numsSize) {
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[len++] = nums[i];
        }
    }
    if (len < numsSize) {
        for (int j = len; j < numsSize; j++) {
            nums[j] = 0;
        }
    }
}
*/