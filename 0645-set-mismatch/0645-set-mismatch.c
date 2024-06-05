/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *ret_arr = (int *)malloc(sizeof(int)*(*returnSize));
    //char *hash = (char *) calloc(numsSize + 1, sizeof(int));
    char *hash = (char *) malloc(sizeof(int)*(numsSize+1));
    memset(hash, 0, sizeof(char)*(numsSize+1));
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }
    for (int i = 1; i <= numsSize; i++) {
        if (hash[i] == 0) ret_arr[1] = i;
        else if (hash[i] == 2) ret_arr[0] = i;
    }
    free(hash);
    return ret_arr;
}


/*
int cmp(const void *a, const void *b) {
    return *(int *)a -*(int *)b;
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int *ret_arr = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    ret_arr[0] = -1;
    ret_arr[1] = 1;
    
    for (int i = 0; i < numsSize-1; i++) {
        // find which one is duplicated
        if (nums[i] == nums[i+1]) {
            ret_arr[0] = nums[i];   // error
        }
        // find which one is lacked
        if (nums[i]+1 != nums[i+1] && nums[i] != nums[i+1]) {
            ret_arr[1] = nums[i]+1;
        }
    }
    if (nums[numsSize-1] != numsSize) {
        ret_arr[1] = numsSize;
    }
    return ret_arr;
}
*/