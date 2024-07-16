bool canConstruct(char* ransomNote, char* magazine) {
    int letters[26] = {0};
    int str_len_ransomNote = strlen(ransomNote);
    int str_len_magazine = strlen(magazine);
    for (int i = 0; i < str_len_magazine; i++) {
        letters[magazine[i]-'a']++;
    }
    for (int i = 0; i < str_len_ransomNote; i++) {
        letters[ransomNote[i]-'a']--;
        if (letters[ransomNote[i]-'a'] < 0) {
            return false;
        }
    }
    return true;
}