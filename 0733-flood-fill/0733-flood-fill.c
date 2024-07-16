/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int original_color) {
    if (sr >= imageSize || sc >= *imageColSize) {
        return;
    }
    if (image[sr][sc] == original_color) {
        image[sr][sc] = color;
        dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
        dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
        dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    if (image[sr][sc] == color) return image;

    dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
    return image;
}