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
int maxCoins(int* piles, int pilesSize) {
    int count = 0;
    quickSort(piles, 0, pilesSize-1);
    for (int i = pilesSize-1-1; i >= pilesSize/3; i -= 2) {
        count += piles[i];
    }
    return count;
}