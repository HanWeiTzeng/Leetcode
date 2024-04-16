int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
// search target at middle = numsSize/2
// end while loop when left = right/
    while (left <= right) {
        int middle = (left + right)/2;
// smaller than nums[middle]. middle = middle+ left/2;
// update left/ right.
        if (target < nums[middle]) {
            right = middle - 1;
        } else if (target > nums[middle]) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}