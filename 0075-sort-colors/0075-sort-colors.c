void swap(int *nums, int index_1, int index_2) {
    int tmp = nums[index_1];
    nums[index_1] = nums[index_2];
    nums[index_2] = tmp;
}

void sortColors(int* nums, int numsSize) {
    int ptr_left = 0, ptr_right = numsSize-1, ptr_iterating = 0;
    while (ptr_left <= ptr_right && ptr_iterating <= ptr_right) {
        while (ptr_left < numsSize -1 && nums[ptr_left] == 0) {
            printf("ptr_left %d.\n", ptr_left+1);
            ptr_left++;
        }
        while (ptr_right >= 0 && nums[ptr_right] == 2) {
            printf("ptr_right %d.\n", ptr_right-1);
            ptr_right--;
        }

        if (ptr_iterating < ptr_right && nums[ptr_iterating] == 2) {
            printf("swap 2 nums[%d] = %d, nums[%d] = %d.\n", ptr_iterating, nums[ptr_iterating], ptr_right, nums[ptr_right]);
            swap(nums, ptr_iterating, ptr_right);
            for (int i = 0; i < numsSize; i++) {
                printf(" %d", nums[i]);
            }
            printf("\n");
        } else if (ptr_iterating > ptr_left && nums[ptr_iterating] == 0) {
            printf("swap 0 nums[%d] = %d, nums[%d] = %d.\n", ptr_left, nums[ptr_left], ptr_iterating, nums[ptr_iterating]);
            swap(nums, ptr_left, ptr_iterating);
            for (int i = 0; i < numsSize; i++) {
                printf(" %d", nums[i]);
            }
            printf("\n");
        } else {
            printf("ptr_iterating = %d.\n", ptr_iterating+1);
            ptr_iterating++;
        }
    }
}