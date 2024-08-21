void paint_island(char** grid, int i, int j, int gridSize, int gridColSize) {
    if (i >= 0 && i < gridSize && j >= 0 && j < gridColSize)
        if (grid[i][j] == '1') {
            grid[i][j] = '2';
            paint_island(grid, i - 1, j, gridSize, gridColSize);
            paint_island(grid, i + 1, j, gridSize, gridColSize);
            paint_island(grid, i, j - 1, gridSize, gridColSize);
            paint_island(grid, i, j + 1, gridSize, gridColSize);
        }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    // create a int count_island to
    int count_island = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            // if (x,y) is 1 check if (x-1,y) (x+1,y) (x,y-1) (x,y+1)
            // change 1 into 2, can avoid count them again.
            if (grid[i][j] == '1') {
                count_island++;
                paint_island(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return count_island;
}