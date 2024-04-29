/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int *nums, int head, int mid, int tail) {
    int size_a = mid - head + 1;
    int size_b = tail- (mid+1) + 1;
    int A[size_a];
    int B[size_b];
    int i;
    int j;
    int k;

    for (i = 0; i < size_a; i++) {
        A[i] = nums[head+i];
    }

    for (j = 0; j < size_b; j++) {
        B[j] = nums[mid+1+j];
    }
    i = 0;
    j = 0;
    k = head;

    while (i < size_a && j < size_b) {
        if (A[i] < B[j]) {
            nums[k] = A[i];
            i++;
        } else {
            nums[k] = B[j];
            j++;
        }
        k++;
    }
    while (i <size_a) {
        nums[k] = A[i];
        k++;
        i++;
    }
    while (j < size_b) {
        nums[k] = B[j];
        k++;
        j++;
    }
}

int *mergesort(int *nums, int head, int tail) {
    if (head < tail) {
        int mid = (head + tail)/2;
        mergesort(nums, head, mid);
        mergesort(nums, mid+1, tail);
        merge(nums, head, mid, tail);
    }
    return nums;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int *ret_arr = (int*)malloc(sizeof(int) * numsSize);
    ret_arr = mergesort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}