bool isPalindrome(int x) {
    int length = 0;
    double reverse_x = 0;
    int array[10] = {0};
    int mod_x = x;
    if (x < 0) return false;
        else if (x < 10) return true;

    while (mod_x != 0) {
        int pa_x;
        pa_x = mod_x%10;    // 1 2 2 1
        mod_x = mod_x/10;   // 123432 12343 .... 1  0
        array[length] = pa_x;  // 1 2 2 1
        length++;       // 0 -> 1 -> 2 -> 5 6 7
    }
    for (int i = 0; i < length/2; i++) {
        if (array[i] != array[length-1-i]) return false;
    }
    return true;
}

/* Previous version
bool isPalindrome(int x) {
    int length = 0;
    double reverse_x = 0;
    int *array = 0; // 0 = null
    int mod_x = x;
    if (x < 0) return false;

    do {
        int pa_x;
        array = realloc(array, sizeof(int)*(length+1));  // [2] = {1, 2, 3 4 3 2, 1}
        pa_x = mod_x%10;    // 1 2 2 1
        mod_x = mod_x/10;   // 123432 12343 .... 1  0
        array[length] = pa_x;  // 1 2 2 1
        length++;       // 0 -> 1 -> 2 -> 5 6 7
    } while (mod_x != 0);

    for (int i = 0; i < length; i++) {
        reverse_x = reverse_x + pow(10,i) * array[length-1-i];
    }

    if (x != (int)reverse_x) {
        return false;
    } else {
        return true;
    }
}
*/