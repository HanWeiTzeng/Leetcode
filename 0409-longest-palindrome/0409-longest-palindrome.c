int longestPalindrome(char* s) {
    int letters[52] = {0};
    int str_len_s = strlen(s);
    for (int i = 0; i < str_len_s; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            letters[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            letters[s[i] - 'A' + 26]++;
        }
    }
    int flag_odd = 0;
    int count = 0;
    for (int i = 0; i < 52; i++) {
        count += letters[i] / 2 * 2;
        if (flag_odd == 0 && letters[i] % 2 == 1) {
            flag_odd = 1;
        }
    }
    if (flag_odd == 1) {
        count++;
    }
    return count;
}