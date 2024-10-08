/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare_arrays(const void *a, const void *b) {
    const int *arr1 = *(const int **)a;  // Dereference twice to get the array
    const int *arr2 = *(const int **)b;
    return arr1[0] - arr2[0]; // Compare based on the first element
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int **ret_arr = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnSize = 0;
    *returnColumnSizes = (int *) malloc(sizeof(int )* intervalsSize);

    // Use qsort to sort the array based on the first element of each sub-array
    qsort(intervals, intervalsSize, sizeof(int *), compare_arrays);

    // start from index 0
    int index_1st = 0;
    int index_2nd = 1;

    while (index_2nd < intervalsSize) {
        // case 0: x01 < x10 => do nothing
        if (intervals[index_1st][1] < intervals[index_2nd][0]) {
            ret_arr[*returnSize] = (int *)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[(*returnSize)] = 2;
            ret_arr[*returnSize][0] = intervals[index_1st][0];
            ret_arr[*returnSize][1] = intervals[index_1st][1];
            *returnSize += 1;
        } else {
        // case 1: x01 >= x10 => merge these two interval.
            intervals[index_2nd][0] = intervals[index_1st][0];
            if (intervals[index_1st][1] > intervals[index_2nd][1]) {
                intervals[index_2nd][1] = intervals[index_1st][1];
            }
        }
        index_1st++;
        index_2nd++;
    }

    // index < intervalsSize-1
    ret_arr[*returnSize] = (int *)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[*returnSize] = 2;
    ret_arr[*returnSize][0] = intervals[index_1st][0];
    ret_arr[*returnSize][1] = intervals[index_1st][1];
    *returnSize += 1;
    return ret_arr;
}