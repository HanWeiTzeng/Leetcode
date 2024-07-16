int search(int* nums, int numsSize, int target) {
    // check middle of array
    int i = 0, j = numsSize - 1;
    int middle = (i + j) / 2;
    // divide it into 2 pieces by bigger than nums[middle] or smaller.
    while (i <= j) {
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            j = middle-1;
        } else {
            i = middle+1;
        }
        middle = (i + j) / 2;
    }

    // check the boundary
    //if (nums[i] == target) {
    //    return i;
    //}
    // return -1 if hit boundary.
    return -1;
}