// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    int middle = (start + end) / 2;
    int test1_version = isBadVersion(middle);
    int test2_version = isBadVersion(middle + 1);

    while (!(test1_version == false && test2_version == true)) {
        if (test1_version == false && test2_version == false) {
            start = middle + 1;
        } else if (test1_version == true && test2_version == true) {
            end = middle - 1;
        }
        middle = (start/2 + end/2);
        if (start % 2 == 1 && end % 2 == 1) {
            middle += 1;
        }
        //printf("middle %d\n", middle);
        test1_version = isBadVersion(middle);
        test2_version = isBadVersion(middle + 1);
    }
    return middle + 1;
}