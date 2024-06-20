void rotate(int* nums, int numsSize, int k) {
    int count = 0;
    int i = 0;
    int pop_out = nums[i];
    int check_list[numsSize];
    memset(check_list, 0, sizeof(check_list));
    check_list[i] = 1;
    // change a[i] to a[i+k], remember % numsSize
    // use variable count to count total change times, need to equal to numsSize
    while (count <= numsSize) {
        i = (i+k) % numsSize;
        int tmp = nums[i];
        nums[i] = pop_out;
        if (check_list[i] == 0) {
            pop_out = tmp;
            check_list[i] = 1;
        } else {
            i = (i+1) % numsSize;
            if (check_list[i] == 1) return;
            pop_out = nums[i];  // don't pop out changed value
            check_list[i] = 1;
        }
        count++;
    }
}