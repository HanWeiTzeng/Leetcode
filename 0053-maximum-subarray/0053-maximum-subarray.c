int max(int a, int b) {
    return ((a)>(b))? (a):(b);
}

int maxSubArray(int* nums, int numsSize) {
    int max_subarray_sum = 0;
    int sum_pre = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            max_subarray_sum = nums[i];  
        } else {
            sum_pre += nums[i-1];
            sum_pre = max(sum_pre, nums[i-1]);
            if (nums[i] > 0 && sum_pre >= 0) {
                max_subarray_sum = max(max_subarray_sum, sum_pre + nums[i]);
            } else if (nums[i] > 0 && sum_pre < 0 || nums[i] <= 0) {
                max_subarray_sum = max(max_subarray_sum, nums[i]);
            }
        }
    }
    return max_subarray_sum;
}