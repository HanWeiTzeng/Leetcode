int hammingWeight(int n) {
    int count_bit_1 = 0;
    while (n != 0) {
        count_bit_1++;
        n &= n-1;
    }
    return count_bit_1;
}