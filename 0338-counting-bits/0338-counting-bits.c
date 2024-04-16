/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
1. 利用 Brian Kernighan\text{Brian Kernighan}Brian Kernighan 算法，
可以在一定程度上进一步提升计算速度。
Brian Kernighan\text{Brian Kernighan}Brian Kernighan 算法的原理是：
对于任意整数 x，令 x=x & (x−1)，逐步把所有的1變成0
2. 也可以像這樣解
*/

int* countBits(int n, int* returnSize) {
    int *ret_arr = (int *) malloc(sizeof(int)*(n + 1));
    for (int i = 0; i <= n; i++) {
        int bw = i;
        ret_arr[i] = bw & 1;
        while (bw >> 1) {
            ret_arr[i] += (bw >> 1) & 1;
            bw = bw >> 1;
        }
    }
    *returnSize = n + 1;
    return ret_arr;
}
}