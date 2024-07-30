bool backspaceCompare(char* s, char* t) {
    // use queue to store s & t
    int s_len = strlen(s);
    int t_len = strlen(t);
    // when encountering # do index -1
    char *queue_s = malloc(sizeof(char)* (s_len+1));
    char *queue_t = malloc(sizeof(char)* (t_len+1));
    // add \0 at index
    int index_s = 0, index_t = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] != '#') {
            queue_s[index_s++] = s[i];
        } else {
            if (index_s != 0)
                index_s--;
        }
    }
    queue_s[index_s] = '\0';

    for (int i = 0; i < t_len; i++) {
        if (t[i] != '#') {
            queue_t[index_t++] = t[i];
        } else {
            if (index_t != 0)
                index_t--;
        }
    }
    queue_t[index_t] = '\0';

    // strcmp them.
    if (strcmp(queue_s, queue_t) != 0) {
        return false;
    }
    return true;
}