char * sortSentence(char * s){
    // create a array for 9 string.
    char **str_arr = (char **) malloc(sizeof(char *)*9);
    // add related string by the tail numbers-1
    char max_number = 0;
    char str_len = 0;
    char *str = (char *) malloc(sizeof(char)*200);
    int k = 0;
    int count = 0;
    int i = 0;
    while (s[i] != '\0') {
        if ('1'<= s[i] && s[i] <= '9') {
            printf("s[i] = %c (number)\n", s[i]);
            str[k] = '\0';
            // create char* return string.
            str_arr[s[i]-'1'] = (char *) malloc(sizeof(char)* (k+1));
            strcpy(str_arr[s[i]-'1'], str);
            k = 0;
            max_number++;
        } else if (s[i] == ' ') {
            count++;
            printf("Hit space.\n");
        } else {
            str[k++] = s[i];
            printf("s[i] = %c\n", s[i]);
            count++;
        }
        i++;
    }

    free(str);
    char *ret_arr = (char *)malloc(sizeof(char)*(count+1));
    printf("max_number %d. count %d\n", max_number, count);
    int l = 0;
    for (int i = 0; i < max_number; i++) {
        strcpy(ret_arr+l, str_arr[i]);
        l += strlen(str_arr[i]);
        if (i < max_number-1) ret_arr[l] = ' ';
        l++;
    }

    free(str_arr);
    return ret_arr;
}