int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 0;
    int right = x;
    while (left <= right) {
        int middle = (left+right)/2;
        if (x/middle == middle && x%middle == 0) return middle;
        else if (x/middle < middle) {
            right = middle-1; // 8: 0 ~ 3
            printf("right %d\n", right);
        } else if (x/middle > middle) { //2nd 8:2~3
            left = middle+1;
            printf("left %d\n", left);
        }
    }
    return left-1;
}