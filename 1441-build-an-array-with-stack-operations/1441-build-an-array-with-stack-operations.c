/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 

char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    int count_all_op = 0;
    int count_target = 0;
    int number = 1;
    while (count_target < targetSize && number <= n) {
        if (target[count_target] == number) {
            count_all_op++;
            number++;
            count_target++;
        } else {
            count_all_op += 2;
            number++;
        }
    }
    char **ret_arr = (char **) malloc (sizeof(char *)*count_all_op);
    count_all_op = 0;
    count_target = 0;
    number = 1;
    while (count_target < targetSize && number <= n) {
        if (target[count_target] == number) {
            ret_arr[count_all_op] = (char *)malloc((4 + 1) * sizeof(char));
            ret_arr[count_all_op++] = "Push";
            //printf("%s ",ret_arr[count_all_op-1]);
            number++;
            count_target++;
        } else {
            ret_arr[count_all_op] = (char *)malloc((4 + 1) * sizeof(char));
            ret_arr[count_all_op++] = "Push";
            ret_arr[count_all_op] = (char *)malloc((3 + 1) * sizeof(char));
            //printf("%s ",ret_arr[count_all_op-1]);
            ret_arr[count_all_op++] = "Pop";
            //printf("%s ",ret_arr[count_all_op-1]);
            number++;
        }
    }
    *returnSize = count_all_op;
    return ret_arr;
}