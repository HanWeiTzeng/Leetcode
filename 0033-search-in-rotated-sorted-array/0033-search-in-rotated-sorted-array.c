int search(int* nums, int numsSize, int target) {
    // use a index to keep the order.
    int index = 0;
    int first_value = nums[0];
    int flag_rotated = 0;
    while (index < numsSize) {
        if (nums[index] == target) {
            return index;
        }
        index++;
    }
    return -1;
}