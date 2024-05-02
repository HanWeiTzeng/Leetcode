bool isUgly(int n) {
    if (n <= 0) return false;

    int pre_n = 0;
    while (n > 1 && pre_n != n) {
        pre_n = n;
        if (n%2 == 0) {
            n /= 2;
        }
        if (n%3 == 0) {
            n /= 3;
        }
        if (n%5 == 0) {
            n /= 5;
        }
    }

    if (n == 1)
        return true;
        else {
            return false;
        }
}