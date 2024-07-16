/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 這題要注意 DFS 深度搜尋要另外寫才有辦法改

void dfs(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int original_color) {
    if (sr < 0 || sc < 0 || sr >= imageSize || sc >= imageColSize[0]) {
        return;
    }
    if (image[sr][sc] == original_color) {
        image[sr][sc] = color;
        dfs(image, imageSize, imageColSize, sr+1, sc, color, original_color);
        dfs(image, imageSize, imageColSize, sr-1, sc, color, original_color);
        dfs(image, imageSize, imageColSize, sr, sc+1, color, original_color);
        dfs(image, imageSize, imageColSize, sr, sc-1, color, original_color);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    if (image[sr][sc] == color) return image;

    dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
    return image;
}