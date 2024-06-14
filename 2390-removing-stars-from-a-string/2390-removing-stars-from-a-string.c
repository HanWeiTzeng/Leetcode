char* removeStars(char* s) {
    char *ret_s = (char *)malloc(sizeof(char)*(strlen(s)+1));
    int i = 0;
    int j = 0;
    // use index i to test
    while(s[i] != '\0') {
        if (s[i] != '*') {
            ret_s[j] = s[i];
            j++;
            i++;
        } else { //s[i] == '*'
            if (j > 0)
            j--;
            i++;
        }
    }
    ret_s[j] = '\0';
    return ret_s;
}