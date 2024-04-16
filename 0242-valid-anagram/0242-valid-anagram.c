
/*
bool isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int collector[26] = {0};
    if (s_len != strlen(t)) return false;

    for (int i = 0; i < s_len; i++) {
        collector[s[i]-'a'] += s[i];
        collector[t[i]-'a'] -= t[i];
    }
    for (int i = 0; i < 26; i++) {
        if (collector[i] != 0) return false;
    }
    return true;
}


官方詳解
作者：力扣官方题解
链接：https://leetcode.cn/problems/valid-anagram/solutions/493231/you-xiao-de-zi-mu-yi-wei-ci-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int cmp(const void* _a, const void* _b) {
    char a = *(char*)_a, b = *(char*)_b;
    return a - b;
}

bool isAnagram(char* s, char* t) {
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t) {
        return false;
    }
    qsort(s, len_s, sizeof(char), cmp);
    qsort(t, len_t, sizeof(char), cmp);
    return strcmp(s, t) == 0;
}

