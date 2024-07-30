/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count_bit(int value) {
    int count = 0;
    while (value != 0) {
        count++;
        value &= (value -1);
    }
    return count;
}

int* countBits(int n, int* returnSize) {
    // create an array with size n
    int* arr = (int*)malloc(sizeof(int) * (n + 1));
    // use for loop for filling up with all element in array in order.
    for (int i = 0; i <= n; i++) {
        arr[i] = count_bit(i);
    }
    *returnSize = n + 1;
    return arr;
}