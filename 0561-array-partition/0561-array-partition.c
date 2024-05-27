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
        while (i < right && nums[i] <= pivot) {
            i++;
        }
        while (j > left && nums[j] >= pivot) {
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
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot-1);
        quickSort(nums, pivot+1, right);
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