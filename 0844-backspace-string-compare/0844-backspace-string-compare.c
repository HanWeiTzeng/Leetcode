// ----->注意


#include <string.h>

char *helper (char* str) {
    int s_len = strlen(str);
    int len = 0;
    char *ret = (char *) malloc (sizeof(char)*(s_len + 1));
    for (int i = 0; i < s_len; i++) {
        if(str[i] != '#') {
            ret[len++] = str[i];
        } else {
            if (len > 0) {               //----->注意
                len--;                      //----->注意
            }
        }
    }
    ret[len] = '\0';
    return ret;
}


bool backspaceCompare(char* s, char* t) {
    return !(strcmp(helper(s), helper(t)));
}


bool backspaceCompare(char s, char t) {
    return !(strcmp(helper(s), helper(t)));
}