bool isPowerOfTwo(int n) {
    char count = 0;
    if (n < 0) return false;
    while (n) {
        if ((n&1) != 0)
        count++;
        if (count > 1) return false;
        n >>= 1;
    }
    if (count == 1) return true;
    return false;
}