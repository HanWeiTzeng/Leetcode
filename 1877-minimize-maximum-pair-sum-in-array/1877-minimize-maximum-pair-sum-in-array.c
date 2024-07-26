int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minPairSum(int* nums, int numsSize){
    // arrange the nums
    qsort(nums, numsSize, sizeof(int), compare);
    // pairing the nums by biggest one with smallest one.
    int biggest = 0;
    for (int i = 0; i < numsSize/2; i++) {
        if (nums[i] + nums[numsSize-1-i] > biggest) {
            biggest = nums[i] + nums[numsSize-1-i];
        }
    }
    // checkout biggest.
    return biggest;
}