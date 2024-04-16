int hammingWeight(uint32_t n) {
    int count_1_num = 0;
    while (n) {
        count_1_num += n % 2;
        n = n >> 1;
    }
    return count_1_num;
}
/*
int hammingWeight(uint32_t n) {
    int count_1_num = 0;
    while (n) {
        count_1_num += 1;
        n &= (n-1);
    }
    return count_1_num;
}
*/