/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to merge two subarrays of arr[]
void merge(int arr[], int left, int mid, int right, int *ori_idx) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int *L_idx = (int*)malloc(n1 * sizeof(int));
    int *R_idx = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        L_idx[i] = ori_idx[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        R_idx[j] = ori_idx[mid + 1 + j];
    }
    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ori_idx[k] = L_idx[i];
            i++;
        } else {
            arr[k] = R[j];
            ori_idx[k] = R_idx[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        ori_idx[k] = L_idx[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        ori_idx[k] = R_idx[j];
        j++;
        k++;
    }

    // Free the allocated memory
    free(L);
    free(R);

    free(L_idx);
    free(R_idx);
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right, int *ori_idx) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, ori_idx);
        mergeSort(arr, mid + 1, right, ori_idx);

        // Merge the sorted halves
        merge(arr, left, mid, right, ori_idx);
    }
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *ori_idx = (int *) malloc(numsSize * sizeof(int));
    int *ret_arr = (int *) malloc(numsSize * sizeof(int));
    int *sorted_arr = (int *) malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        ori_idx[i] = i;
        sorted_arr[i] = nums[i];
    }

    mergeSort(sorted_arr, 0, numsSize - 1, ori_idx);

    for (int i = numsSize - 1; i > 0; i--) {
        int j = 0;
        ret_arr[i] = i;
        while (j < i && sorted_arr[i-j] == sorted_arr[i - 1 -j]) {
            ret_arr[i]--;
            j++;
        }
    }
    ret_arr[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sorted_arr[ori_idx[i]] = ret_arr[i];
    }

    free(ori_idx);
    free(ret_arr);

    *returnSize = numsSize;
    return sorted_arr;
}