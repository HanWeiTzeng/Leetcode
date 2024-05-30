int mySqrt(int x) {
    if (x == 0) return 0;
    int left = 0;
    int right = x;
    while (left <= right) {
        int middle = (right+left)/2;
        if (middle == 0) middle = 1;
        if (x/middle == middle && x%middle == 0) {return middle;}
        else if (middle > x/middle) {
            right = middle-1;
        } else if (middle <= x/middle) {
            left = middle+1;
        }
    }
    return left-1;
}