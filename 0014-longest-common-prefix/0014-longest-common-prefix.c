#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize <= 1)
        return strs[strsSize - 1];
    int len_s = strlen(strs[0]);
    char* ret_s = malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(ret_s, strs[0]);
    int i, j;
    for (i = 0; i < len_s; i++) {
        for (j = 0; j < strsSize - 1; j++) {
            if (strs[j][i] != strs[j + 1][i]) {
                ret_s[i] = '\0';
                return ret_s;
            }
        }
    }

    return ret_s;
}