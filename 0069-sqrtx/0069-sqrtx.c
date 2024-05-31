int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 0;
    int right = x;
    while (left <= right) {
        int middle = (right+left)/2;
        if (x/middle == middle && x%middle == 0) {return middle;}
        else if (x/middle < middle) {
            right = middle-1;
        } else if (x/middle >= middle) {
            left = middle+1;
        }
    }
    return left-1;
}