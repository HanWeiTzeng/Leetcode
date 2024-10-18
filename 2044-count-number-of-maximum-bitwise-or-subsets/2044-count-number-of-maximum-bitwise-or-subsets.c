int countMaxOrSubsets(int* nums, int numsSize) {
    // use OR to count the max value.
    int maximum = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        maximum |= nums[i];
    }
    // run all the subset.
    int amount_subset = 1;
    for (int i = 0; i < numsSize; i++) {
        amount_subset *= 2; 
    }
    amount_subset--;
    int non_empty_subset_all = maximum;
    // run all set;
    for (int i = 1; i <= amount_subset; i++) {
        non_empty_subset_all = maximum;
        //printf(" %d ",i );
        int n = 1;
        int idx_bit = 0;
        while (n <= i) {
            if ((n & i) != 0) {
                //printf("i %d nums[%d] %d.\n", i, idx_bit, nums[idx_bit]);
                non_empty_subset_all &= ~(nums[idx_bit]);
            }
            if (non_empty_subset_all == 0) {
                count++;
                //printf("+1.\n");
                break;
            }
            n = n << 1;
            idx_bit += 1;
        }
    }
    return count;
}