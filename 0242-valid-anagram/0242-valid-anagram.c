#include <string.h>

bool isAnagram(char* s, char* t) {
    // make a hash table of 26 char.
    int letter[26] = {0};
    int str_len_s = strlen(s); 
    int str_len_t = strlen(t); 
    
    if (str_len_s != str_len_t) return false;

    for (int i = 0; i < str_len_s; i++) {
        letter[s[i]-'a']++;
        letter[t[i]-'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (letter[i] != 0) return false;
    }
    return true;
}