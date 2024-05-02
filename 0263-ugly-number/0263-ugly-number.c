bool isUgly(int n) {
    if (n <= 0) return false;

    int pre_n = 0;
    while (n > 1 && pre_n != n) {
        pre_n = n;
        if ((n/2)*2 == n) {
            n /= 2;
        }
        if ((n/3)*3 == n) {
            n /= 3;
        }
        if ((n/5)*5 == n) {
            n /= 5;
        }
    }

    if (n == 1)
        return true;
        else {
            return false;
        }
}