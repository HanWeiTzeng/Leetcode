bool isUgly(int n) {
    if (n <= 0) return false;
    int tmp = 0;
    int pre_n = 0;
    while (n > 1 && pre_n != n) {
        pre_n = n;
        tmp = n/2;
        if (n == tmp*2) {
            n = tmp;
        }
        tmp = n/3;
        if (n == tmp*3) {
            n = tmp;
        }
        tmp = n/5;
        if (n == tmp*5) {
            n = tmp;
        }
    }
    if (n == 1)
        return true;
        else {
            return false;
        }
}