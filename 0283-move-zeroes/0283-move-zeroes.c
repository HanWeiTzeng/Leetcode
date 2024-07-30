void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize) {
    int index_zero = 0, index_none_zero = 0;
    // detect 0 and use swap to switch
    while (index_zero < numsSize && index_none_zero < numsSize) {
        /*while (nums[index_zero] != 0) {
            printf("index_zero nums[%d] = %d\n", index_zero, nums[index_zero]);
            index_zero++;
        }*/
        while (nums[index_none_zero] == 0 && index_none_zero < numsSize) {
            printf("index_none_zero nums[%d] = %d\n", index_none_zero, nums[index_none_zero]);
            index_none_zero++;
        }
        swap(nums + index_zero, nums + index_none_zero);
        index_zero++;
        index_none_zero++;
    }
}