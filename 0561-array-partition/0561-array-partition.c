void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    int j = right - 1;
    while (i < j) {
        while (i <= j && nums[i] <= pivot) {
            i++;
        }
        while (j >= i && nums[j] >= pivot) {
            j--;
        }
        if (i < j) {
            swap(&nums[i], &nums[j]);
        }
    }
    if (nums[i] > pivot) {
        swap(&nums[i], &nums[right]);
    }
    return i;
}
void quickSort(int *nums, int left, int right) {
    if (left < right) {
        int partition_pos = partition(nums, left, right);
        quickSort(nums, left, partition_pos-1);
        quickSort(nums, partition_pos+1, right);
    }
}
int arrayPairSum(int* nums, int numsSize) {
    int count = 0;
    //mergesort(nums, 0, numsSize-1);
    quickSort(nums, 0, numsSize-1);
    for (int i = 0; i < numsSize; i += 2) {
        count += nums[i];
    }
    return count;
}