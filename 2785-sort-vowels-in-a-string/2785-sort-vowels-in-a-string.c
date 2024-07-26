int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

char * sortVowels(char * s){
    int len_s = strlen(s);
    int position[len_s];
    int vowel[len_s];
    int count = 0;
    // check those position where the vowels belong.
    for (int i = 0 ; i < len_s; i++) {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'i' || s[i] == 'I' || s[i] == 'e' || s[i] == 'E' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            position[count] = i;
            vowel[count] = s[i];
            count++;
        }
    }
    // store the positions and store all vowels value then arrange vowels without position.
    qsort(vowel, count, sizeof(int), compare);
    // put them back to s.
    for (int i = 0; i < count; i++) {
        s[position[i]] = vowel[i];
    }
    // Return s.
    return s;
}