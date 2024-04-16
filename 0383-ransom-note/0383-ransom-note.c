// Runtime: 3ms

bool canConstruct(char* ransomNote, char* magazine) {
    int countLetter[256] = {0};
    int sr = strlen(ransomNote);
    int sm = strlen(magazine);

    for (int i = 0; i < sm; i++) {
        countLetter[magazine[i]]++;
    }

    for (int i = 0; i < sr; i++){
        if (--countLetter[ransomNote[i]] < 0) return false;
    }
    return true;
}


// ====================
///Runtime: 6ms
 /*
bool canConstruct(char* ransomNote, char* magazine) {
    int a[26] = {0};
    int i = 0;
    while (magazine[i] != '\0') {
        a[magazine[i]-'a']++;
        i++;
    }
    i = 0;
    while (ransomNote[i] != '\0') {
        if (--a[ransomNote[i]-'a'] < 0) return false;
        i++;
    }
    return true;
}
 */