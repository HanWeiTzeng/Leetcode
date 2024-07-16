int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int most_value = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == most_value) {
            count++;
        } else {
            count--;
            if (count < 0) {
                count = 1;
                most_value = nums[i];
            }
        }
    }
    return most_value;
}