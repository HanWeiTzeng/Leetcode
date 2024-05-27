
/*
void mergeSortedElement(int *nums, int left, int middle, int right) {
    int len_A = middle - left + 1;
    int len_B = right - (middle);
    int A[len_A];
    int B[len_B];
    for (int i = 0; i < len_A; i++)    A[i] = nums[left+i];
    for (int i = 0; i < len_B; i++)    B[i] = nums[middle+1+i];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < len_A && j < len_B) {
        if (A[i] < B[j]) {
            nums[k] = A[i];
            i++;
        } else {
            nums[k] = B[j];
            j++;
        }
        k++;
    }
    while (i < len_A) {
        nums[k] = A[i];
        i++;
        k++;
    }
    while (j < len_B) {
        nums[k] = B[j];
        j++;
        k++;
    }
}
void mergesort(int *nums, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergesort(nums, left, middle);
        mergesort(nums, middle+1, right);
        mergeSortedElement(nums, left, middle, right);
    }
}
*/
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
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    for (int i = 0; i < numsSize; i += 2) {
        count += nums[i];
    }
    return count;
}