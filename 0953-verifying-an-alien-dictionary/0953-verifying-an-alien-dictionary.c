bool isAlienSorted(char** words, int wordsSize, char* order) {
    //find the words[i][0] in order
    // compare to words[i+1][0]
    //words[i][0] words[i+1][0]
    int i = 0, j = 0;
    while (i < wordsSize-1) {
        // check words[i][j] in which position in order
        int pos1 = 0, pos2 = 0;
        while  (order[pos1] != words[i][j]) {
            pos1++;
        }
        while  (order[pos2] != words[i+1][j]) {
            pos2++;
        }
        printf("%c %d", order[pos1],pos1);
        printf("%c %d\n", order[pos2],pos2);
        if (pos1 > pos2) {
            return false;
        } else if (pos1 < pos2) {
            i++;
        } else {
            j++;
            if (words[i][j] != '\0' && words[i+1][j] == '\0') {
                return false;
            } else if (words[i][j] == '\0') {
                i++;
                j = 0;
            }
        }
    }
    return true;
}