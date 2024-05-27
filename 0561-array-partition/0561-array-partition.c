void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = (low);      // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;    // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]);
    return (i);
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