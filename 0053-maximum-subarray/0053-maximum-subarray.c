int maxSubArray(int* nums, int numsSize) {
    int max_subarray_tv = 0;
    int idx = 0;
    int sum_pre = 0;
    int i = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            max_subarray_tv = nums[i];  
        } else if (nums[i] > 0) { //nums[i]=4, i=8
            sum_pre += nums[i-1];
            printf("sum_pre %d\n", sum_pre);
            if (nums[i-1] > sum_pre) {
                sum_pre = nums[i-1];
                printf("Change sum_pre %d\n", sum_pre);
            }
            //for (int j = idx; j < i; j++) { //j=3, j<8, j++
            //    sum_pre += nums[j];  //sum_pre = 1
            //}
            if (sum_pre < 0) {
                if (nums[i] > max_subarray_tv) {
                    max_subarray_tv = nums[i];  // 
                    //idx = i;  // 3
                }
                idx = i;  // 3
            } else if (sum_pre >= 0 && sum_pre + nums[i] > max_subarray_tv) {
                max_subarray_tv = sum_pre + nums[i];  // max_subarray_tv=5+1=6  
            }
        } else {
            sum_pre += nums[i-1];
            printf("sum_pre %d\n", sum_pre);
            if (nums[i-1] > sum_pre) {
                sum_pre = nums[i-1];
                printf("Change sum_pre %d\n", sum_pre);
            }
            if (nums[i] > max_subarray_tv) {
                max_subarray_tv = nums[i];
                idx = i;
            }
        }
        //sum_pre = 0;
    }
    return max_subarray_tv;
}