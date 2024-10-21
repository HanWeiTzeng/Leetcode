typedef struct {
    char subStr[17];
    UT_hash_handle hh;
} Hash;

Hash *g_hash;

void Free(void)
{
    Hash *iter, *tmp;
    HASH_ITER(hh, g_hash, iter, tmp) {
        if (iter) {
            HASH_DEL(g_hash, iter);
            free(iter);
        }
    }
}

void Dfs(char *s, int n, int idx, int *cnt, int *ret)
{
    if (idx == n) {
        *ret = fmax(*ret, *cnt);
        return;
    }
    for (int len = 1; len <= n - idx; ++len) {  // 枚举子串的长度
        char subStr[17] = {0};
        strncpy(subStr, s + idx, len);
        Hash *tmp = NULL;
        HASH_FIND_STR(g_hash, subStr, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(Hash));
            strcpy(tmp->subStr, subStr);
            ++(*cnt);
            HASH_ADD_STR(g_hash, subStr, tmp);
            // printf("substr = %s, idx = %d, cnt = %d\n", subStr, idx, *cnt);  // 调试语句        
            Dfs(s, n, idx + len, cnt, ret);
            // 回溯，状态重置
            HASH_DEL(g_hash, tmp);      // 执行dfs之前的操作的 逆向操作
            free(tmp);
            --(*cnt);
        }
    }
}

int maxUniqueSplit(char * s){
    g_hash = NULL;
    int n = (int)strlen(s);
    int ret = 0;
    int cnt = 0;
    Dfs(s, n, 0, &cnt, &ret);
    Free();

    return ret;
}
    /*
int maxUniqueSplit(char* s) {

    // It needs to divide into substrings in order.
    // create a set of substrings
    char **ret_sub_string = (char **) malloc (sizeof(char *) * (strlen(s)));
    // need to malloc the memory to each string.
    int repeat_record[26];
    int repeat_record_b[26];
    
    int count_substring = 0;
    int count_substring_b = 0;
    int j;

    for (int i = 0; i < strlen(s); i++) {
        ret_sub_string[i] = (char *) malloc(sizeof(char) * (strlen(s)+2));
        repeat_record_b[s[i]-'a']++;
        repeat_record[s[i]-'a']++;
    }

    for (int i = 0; i < strlen(s); i++) {
        j = 0;
        ret_sub_string[i][j++] = s[i];
        if (repeat_record[s[i]-'a'] > 1){
            repeat_record[s[i]-'a']--;
            ret_sub_string[i][j++] = s[i+1];
            repeat_record[s[i+1]-'a']--;
            ret_sub_string[i][j++] = '\0';
            printf("%s ", ret_sub_string[i]);
            if (s[i+1] == '\0')
                count_substring--;
            i++;
        } else {
            ret_sub_string[i][j++] = '\0';
            printf("%s ", ret_sub_string[i]);
        }
        count_substring++;
    }
    printf("count_substring %d.\n", count_substring);
    printf("\n");
    // 從後面算

    for (int i = strlen(s)-1; i >= 0; i--) {
        j = 0;
        ret_sub_string[i][j++] = s[i];
        if (repeat_record_b[s[i]-'a'] > 1) {
            repeat_record_b[s[i]-'a']--;
            repeat_record_b[s[i-1]-'a']--;
            if( i-1 >= 0)
            ret_sub_string[i][j++] = s[i-1];
            ret_sub_string[i][j++] = '\0';
            printf("%s ", ret_sub_string[i]);
            i--;
        } else {
            ret_sub_string[i][j++] = '\0';
            printf("%s ", ret_sub_string[i]);
        }
        count_substring_b++;
    }
    printf("count_substring_b %d.\n", count_substring_b);
    if (count_substring_b > count_substring) {
        return count_substring_b;
    } else {
        return count_substring;
    }
}
*/