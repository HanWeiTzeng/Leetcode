int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    //printf("trustSize %d ",trustSize);
    //printf("*trustColSize %d",*trustColSize);
    int all_pro_jg[n];

    for (int i = 0; i < n; i++) {
        all_pro_jg[i] = 0;
    }

    for (int i = 0; i < trustSize; i++) {
        all_pro_jg[trust[i][*trustColSize-1]-1]++;
    }

    for (int i = 0; i < trustSize; i++) {
        all_pro_jg[trust[i][*trustColSize-2]-1]--;
    }

    for (int i = 0; i < n; i++) {
        if (all_pro_jg[i] == n-1) return i+1;
    }
    return -1;
}