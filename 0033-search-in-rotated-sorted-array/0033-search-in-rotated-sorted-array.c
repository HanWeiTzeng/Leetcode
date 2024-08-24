int search(int* nums, int numsSize, int target) {
    // divide the array into two parts.
    // find the one which is ascending, and check if target is belong to this part.
    // if yes, check out this part, if not, check out the other part.
    int first = 0;
    int last = numsSize - 1;
    int middle = (first + last) / 2;
    if (numsSize == 1) {
        if (nums[0] == target) {
            return 0;
        } else 
            return -1;
    } else if (numsSize == 2) {
        if (nums[0] == target)
            return 0;
            else if (nums[1] == target)
                return 1;
                else
                    return -1;
    }

    while (first < last) {
        printf("nums[first = %d] = %d, nums[middle = %d] = %d, nums[last = %d] = %d.\n", first, nums[first], middle, nums[middle], last, nums[last]);
        if (nums[middle] == target) return middle;
        if (nums[first] <= nums[middle-1]) {
            if (nums[first] <= target && target <= nums[middle-1]) {
                printf("AAA");
                /*
                if (nums[first] == target)
                    return first;
                    else if (target == nums[middle-1]) {
                        return middle - 1;
                    }
                */
                last = middle - 1;
            } else {
                first = middle + 1;
            }
            middle = (first + last) / 2;
        } else if (nums[middle+1] <= nums[last]) {
            if (nums[middle+1] <= target && target <= nums[last]) {
                //printf("BBB");
                if (nums[middle+1] == target)
                    return middle+1;
                    else if (target == nums[last]) {
                        return last;
                    }
                first = middle + 1;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
    }
    if (nums[middle] == target) return middle;
    return -1;
}