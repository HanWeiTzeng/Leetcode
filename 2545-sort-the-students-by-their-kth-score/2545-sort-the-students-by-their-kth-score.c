/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int** score1,int** score2) {
    int *tmp = *score1;
    *score1 = *score2;
    *score2 = tmp;
}

int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = scoreSize;
    *returnColumnSizes = scoreColSize;
    for (int i = 0; i < scoreSize-1; i++) {
        for (int j = scoreSize-1; j > i; j--) {
            //printf("i = %d, j = %d\n", i, j);
            // compare score[i][k]
            if (score[j-1][k] < score[j][k]) {
                // swap hold rowscore
                swap(&score[j-1], &score[j]);
            }
        }
    }
    //printf("scoreSize %d\n", scoreSize);
    //printf("scoreColSize %d\n", scoreColSize);
    return score;
}