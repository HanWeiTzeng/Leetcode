/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *hash_table1 = (int *)malloc(sizeof(int)* 1001);
    int *hash_table2 = (int *)malloc(sizeof(int)* 1001);
    int *ret_arr = (int *)malloc(sizeof(int)* 1001);
    int j = 0;

    memset(hash_table1, 0, sizeof(int)*(1001));
    memset(hash_table2, 0, sizeof(int)*(1001));
    for (int i = 0; i < nums1Size; i++)
        hash_table1[nums1[i]]++;
    for (int i = 0; i < nums2Size; i++)
        hash_table2[nums2[i]]++;
    for (int i = 0; i < 1001; i++) {
        if (hash_table1[i] != 0 && hash_table2[i] != 0) {
            ret_arr[j++] = i;
        }
    }
    *returnSize = j;
    return ret_arr;
}