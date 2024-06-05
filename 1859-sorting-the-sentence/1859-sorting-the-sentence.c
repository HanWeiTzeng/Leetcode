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
            str[k] = '\0';
            // create char* return string.
            str_arr[s[i]-'1'] = (char *) malloc(sizeof(char)* (k+1));
            strcpy(str_arr[s[i]-'1'], str);
            k = 0;
            max_number++;
        } else if (s[i] == ' ') {
            count++;
        } else {
            str[k++] = s[i];
            count++;
        }
        i++;
    }
    free(str);
    k = 0;
    char *ret_arr = (char *)malloc(sizeof(char)*(count+1));
    for (int i = 0; i < max_number; i++) {
        strcpy(ret_arr+k, str_arr[i]);
        k += strlen(str_arr[i]);
        ret_arr[k] = ' ';
        k++;
    }
    ret_arr[k-1] = '\0';

    free(str_arr);
    return ret_arr;
}