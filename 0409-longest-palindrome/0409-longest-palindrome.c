//哈希表也可以用

int longestPalindrome(char* s) {
    int count_letter[126] = {0};
    int str_len_s = strlen(s);
    int count = 0;

    for (int i = 0; i < str_len_s; i++) {
        count_letter[s[i]]++;
    }

    for (int i = 0; i < 126; i++) {
        count += count_letter[i] - count_letter[i]%2;     // 重要算法  免除判斷
    }

    if (count != str_len_s) return count+1;
    return count;
}