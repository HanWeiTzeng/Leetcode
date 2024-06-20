void rotate(int* nums, int numsSize, int k) {
    // reduce times.
    k = k % numsSize;
    int count = 0;
    int i = 0;
    int pop_out = nums[i];     // 1
    int check_list[numsSize];
    memset(check_list, 0, sizeof(check_list));
    //check_list[i] = 1;
    // change a[i] to a[i+k] // remember % numsSize
    // use count to count total change times, need to equal to numsSize
    while (count <= numsSize) {
        i = (i+k) % numsSize;   // 3
        int tmp2 = nums[i];    // 4
        nums[i] = pop_out;   // 1
        if (check_list[i] == 0) {
            pop_out = tmp2;    //tmp1 = 4
            check_list[i] = 1;
        } else {
            i = (i+1) % numsSize;
            if (check_list[i] == 1) return;
            pop_out = nums[i];
            check_list[i] = 1;
        }
        printf("nums[%d] %d \n", i, nums[i]);
        count++;
    }
}