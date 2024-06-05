/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void merge(int **arr, int left, int mid, int right, int l, int* scoreColSize) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int **L = (int **)malloc(n1 * sizeof(int*));
    int **R = (int **)malloc(n2 * sizeof(int*));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i][l] >= R[j][l]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the allocated memory
    free(L);
    free(R);
}

// Function to implement Merge Sort
void mergeSort(int **arr, int left, int right, int k, int* scoreColSize) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, k, scoreColSize);
        mergeSort(arr, mid + 1, right, k, scoreColSize);

        // Merge the sorted halves
        merge(arr, left, mid, right, k, scoreColSize);
    }
}


int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = scoreSize;
    *returnColumnSizes = scoreColSize;
    int **ret_arr = (int **)malloc(*returnSize * sizeof(int*));
    for (int i = 0; i < scoreSize; i++) {
        ret_arr[i] = score[i];
    }
    mergeSort(ret_arr, 0, scoreSize-1, k, scoreColSize);
    return ret_arr;
}