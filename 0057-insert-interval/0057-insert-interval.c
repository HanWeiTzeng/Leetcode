/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int push_interval(int** interval, int intervalsSize, int index, int* newinterval, int newIntervalSize, int* returnSize, int **ret_arr) {
    if (newinterval[0] <= interval[index][0]) {
        // start from newinterval[0]
        ret_arr[*returnSize][0] = newinterval[0];
    } else {
        // start from interval[index]
        ret_arr[*returnSize][0] = interval[index][0];
    }
    if (newinterval[1] <= interval[index][1]) {
        ret_arr[(*returnSize)][1] = interval[index][1];
        return ++index;
    } else {
        // can de-size.
        index++;
        while (index < intervalsSize) {
            if (newinterval[1] < interval[index][0]) {  // 5 < 6
                ret_arr[(*returnSize)][1] = newinterval[1];
                return index;
            } else { //if (newinterval[1] >= interval[index][0]) {
                // check.
                if (newinterval[1] <= interval[index][1]) {
                    ret_arr[(*returnSize)][1] = interval[index][1];
                    return ++index;
                } else {
                    index++;
                }
            }
        }
        if (index == intervalsSize) {
            ret_arr[(*returnSize)][1] = newinterval[1];
            return index;
        }
    }
    return 0;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc((intervalsSize+1) * sizeof(int));
    int added = 0;
    // intervalsSize 總共幾組, intervalsColSize[0] = 2.
    int **ret_arr = (int **)malloc(sizeof(int *)*(intervalsSize+1));
    for (int i = 0; i < intervalsSize+1; i++) {
        ret_arr[i] = (int *) malloc(sizeof(int)*2);
    }
    int i = 0;
    if (intervalsSize > 0 && intervals[i][0] > newInterval[1]) {
        for (int h = 0; h < newIntervalSize; h++) {
            ret_arr[*returnSize][h] = newInterval[h];
        }
        *((*returnColumnSizes) + *returnSize) = 2;
        *returnSize = *returnSize + 1;
        added = 1;
    }
    while (i < intervalsSize) {
        if (intervals[i][0] > newInterval[1] && added == 0) {
            for (int j = 0; j < newIntervalSize; j++) {
                ret_arr[*returnSize][j] = newInterval[j];
            }
            added = 1;
            *((*returnColumnSizes) + *returnSize) = 2;
            *returnSize = *returnSize + 1;
        }
        if (intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1]) {
            for (int j = 0; j < intervalsColSize[i]; j++) {
                ret_arr[*returnSize][j] = intervals[i][j];
            }
            *((*returnColumnSizes) + *returnSize) = 2;
            *returnSize = *returnSize + 1;
            i++;
        } else {
            i = push_interval(intervals, intervalsSize, i, newInterval, newIntervalSize, returnSize, ret_arr);
            added = 1;
            *((*returnColumnSizes) + *returnSize) = 2;
            *returnSize = *returnSize + 1;
        }
    }
    if (*returnSize == 0 || added == 0) {
        for (int h = 0; h < newIntervalSize; h++) {
            ret_arr[*returnSize][h] = newInterval[h];
        }
        *((*returnColumnSizes) + *returnSize) = 2;
        *returnSize = *returnSize + 1;
    }
    return ret_arr;
}