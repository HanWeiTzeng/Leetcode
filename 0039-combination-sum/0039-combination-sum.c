/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *ansColumnSize;
int ansSize;

void dfs(int* candidates, int candidatesSize, int target, int** ret_ans, int index, int count, int* tmp_arr) {
    // deal with target < 0 :done
    if (target < 0 || index == candidatesSize) {
        return;
    } else if (target == 0) {
        // deal with target = 0: TBD
        ansColumnSize[ansSize] = count;
        ret_ans[ansSize] = (int *) malloc(sizeof(int)* count);
        for (int i = 0; i < count; i++) {
            ret_ans[ansSize][i] = tmp_arr[i];
        }
        ansSize++;
        return;
    }

    // deal with target > 0: done
    int newtarget = target - candidates[index];
    if (newtarget >= 0) {
        tmp_arr[count] = candidates[index];
        dfs(candidates, candidatesSize, newtarget, ret_ans, index, count+1, tmp_arr);
    }
    dfs(candidates, candidatesSize, target, ret_ans, index+1, count, tmp_arr);
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ret_ans = (int**) malloc(sizeof(int*) * 1001);
    ansColumnSize = malloc(sizeof(int) * 1001);
    ansSize = 0;
    int tmp_arr[40];
    // create an array to store temporate array which is candicate
    dfs(candidates, candidatesSize, target, ret_ans, 0, 0, tmp_arr); //index;
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ret_ans;
}