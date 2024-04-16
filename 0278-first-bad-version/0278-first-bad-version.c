// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// 二分法:

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int middle = left + (right - left)/2;
        if (isBadVersion(middle)) {
            if (middle-left <= 1) {
                if (isBadVersion(left)) return left;
                    else return middle;
            } else
            right = middle;
        } else {
            left = middle+1;
        }
        middle = (left + right)/2;
    }
    return left;
}


// 暴力:
/*
int firstBadVersion(int n) {
    while (isBadVersion(n--));
    return n+2;
}
*/