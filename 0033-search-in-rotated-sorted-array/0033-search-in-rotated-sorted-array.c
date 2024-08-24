int search(int* nums, int numsSize, int target) {
    // divide the array into two parts.
    // find the one which is ascending, and check if target is belong to this part.
    // if yes, check out this part, if not, check out the other part.
    int first = 0;
    int last = numsSize - 1;
    int middle = (first + last) / 2;

    /*
    if (numsSize == 1) {
        if (nums[0] == target) {
            return 0;
        } else 
            return -1;
    } 
    else if (numsSize == 2) {
        if (nums[0] == target)
            return 0;
            else if (nums[1] == target)
                return 1;
                else
                    return -1;
    }*/

    while (first < last) {
        //printf("nums[first = %d] = %d, nums[middle = %d] = %d, nums[last = %d] = %d.\n", first, nums[first], middle, nums[middle], last, nums[last]);
        if (nums[middle] == target) return middle;
        if (nums[first] <= nums[middle]) {
            if (nums[first] <= target && target <= nums[middle]) {
                last = middle;
            } else {
                first = middle + 1;
            }
            middle = (first + last) / 2;
        } else if (nums[middle] <= nums[last]) {
            if (nums[middle] <= target && target <= nums[last]) {
                first = middle;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
    }
    if (nums[middle] == target) return middle;
    return -1;
}