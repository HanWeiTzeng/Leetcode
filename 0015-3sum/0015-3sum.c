/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int base = 100;
    int** ret_matrix = (int**)malloc(sizeof(int*) * base);
    int sum = 0;
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * base);
    qsort(nums, numsSize, sizeof(int), cmp);
    int j, k;
    // use 2 pointers i j to calculate sum
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ret_matrix[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;

                ret_matrix[*returnSize][0] = nums[i];
                ret_matrix[*returnSize][1] = nums[j];
                ret_matrix[*returnSize][2] = nums[k];
                *returnSize += 1;
                if (*returnSize == base) {
                    base += 100;
                    ret_matrix =
                        (int**)realloc(ret_matrix, sizeof(int*) * base);
                    *returnColumnSizes =
                        (int*)realloc(*returnColumnSizes, sizeof(int) * base);
                }
            // 记录符合要求的两个数，进行去重
            int num1 = nums[j], num2 = nums[k];
                while (nums[j] == num1 && j < k)
                    j++;
                while (nums[k] == num2 && j < k)
                    k--;
            } else if (sum < 0) j++;
            else k--;
        }
    }
return ret_matrix;
}