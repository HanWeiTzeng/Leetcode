/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

int ansSize;
//int count = 0;
int* ansColumnSize;

void helper(int* candidates, int candidatesSize, int index, int target, int **ans, int *tmp_arr, int count) {
    if (index == candidatesSize) {
        return;
    }
    if (target == 0) {
        ans[ansSize] = (int *) malloc(sizeof(int) * count);
        for (int i = 0; i < count; ++i) {
            ans[ansSize][i] = tmp_arr[i];
        }
        ansColumnSize[ansSize++] = count;
        //printf(" count = %d, ", count_1);
        //printf("Finded.\n");
        return;
    }
    helper(candidates, candidatesSize, index+1, target, ans, tmp_arr, count);

    int new_target = target - candidates[index];
    if (new_target >= 0) {
        tmp_arr[count] = candidates[index];
        //printf("target = %d. candidates[%d] = %d. count = %d\n", target, index, candidates[index], count);
        helper(candidates, candidatesSize, index, new_target, ans, tmp_arr, count+1);
        count;
    }

}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    // use the first candidates element, and minize it from target.
    int** ans = malloc(sizeof(int*) * 1001);
    ansColumnSize = malloc(sizeof(int) * 1001);
    int tmp_arr[40];
    ansSize = 0;
    helper(candidates, candidatesSize, 0, target, ans, tmp_arr, 0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ans;
}