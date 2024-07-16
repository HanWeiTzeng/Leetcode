bool isPalindrome(char* s) {
    int str_len_s = strlen(s);
    char* new_s = (char *) malloc(sizeof(char) * str_len_s);
    if (str_len_s <= 1) {
        return true;
    }
    int count = 0;
    // convert uppercase into lowercase
    for (int i = 0; i < str_len_s; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            new_s[count++] = s[i]-'A'+'a';
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            new_s[count++] = s[i];
        } else if (s[i] >= '0' && s[i] <= '9') {
            new_s[count++] = s[i];
        }
    }
    for (int i = 0; i < count/2; i++) {
        if (new_s[i] != new_s[count - i -1]) {
            return false;
        }
    }
    return true;
}