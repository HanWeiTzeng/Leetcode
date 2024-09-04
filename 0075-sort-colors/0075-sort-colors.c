void sortColors(int* nums, int numsSize) {
    int count_amounts[3] = {0};
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            count_amounts[0]++;
        else if (nums[i] == 1)
            count_amounts[1]++;
        else if (nums[i] == 2)
            count_amounts[2]++;
    }
    int i = 0;
    while (i < count_amounts[0]) {
        nums[i++] = 0;
    }
    while (i < count_amounts[1] + count_amounts[0]) {
        nums[i++] = 1;
    }
    while (i < count_amounts[2] + count_amounts[1] + count_amounts[0]) {
        nums[i++] = 2;
    }
}