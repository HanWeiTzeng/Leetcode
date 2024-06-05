/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the partitioning index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
bool check_arith(int *array, int arr_size) {
    int common_difference = array[1] - array[0];
    for (int i = 1; i < arr_size-1; i++) {
        if (array[i+1]-array[i] != common_difference) {
            return false;
        }
    }
    return true;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool *return_bool = (bool *)malloc(sizeof(bool)*(*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        int length = r[i]-l[i]+1;
        int *check_arithmetic_arr = (int *)malloc(sizeof(int)*(length));
        for (int j = 0; j < length; j++) {
            check_arithmetic_arr[j] = nums[l[i]+j];
        }
        quickSort(check_arithmetic_arr, 0, length-1);
        printArray(check_arithmetic_arr, length);
        return_bool[i] = check_arith(check_arithmetic_arr, length);
    }
    return return_bool;
}