
void becomes_rotten(int** grid, int i, int j, int gridSize, int gridColSize, int *ptr_count_rot_orange, int rot_orange_index[][2]) {
    if (i >= 0 && i < gridSize && j >= 0 && j < gridColSize) {
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            rot_orange_index[*ptr_count_rot_orange][0] = i;
            rot_orange_index[*ptr_count_rot_orange][1] = j;
            *ptr_count_rot_orange += 1;
        }
    }
}



int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    // create a int count_current_rot_times to
    int count_current_rot_times = 0;

    int rot_orange_index[100][2] = {};/*
    int **rot_orange_index = (int **)malloc(100 * sizeof(int *));
    for (int i = 0; i < 100; i++) {
        rot_orange_index[i] = (int *)malloc(2 * sizeof(int));  // 2 columns to store (i, j)
    }*/

    int count_rot_orange = 0;
    int total_orange = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                rot_orange_index[count_rot_orange][0] = i;
                rot_orange_index[count_rot_orange][1] = j;
                count_rot_orange++;
                total_orange++;
            }
            if (grid[i][j] == 1) {
                total_orange++;
            }
        }
    }

    if (count_rot_orange == total_orange) return count_current_rot_times;

    // check out all rotten orange index, and keep all index which become rotten.
    int round_times = 0;
    int x_round = 0;

    while (round_times < count_rot_orange) {
        round_times = count_rot_orange;
        
        for (int i = x_round; i < round_times; i++) {
            int x = rot_orange_index[i][0];
            int y = rot_orange_index[i][1];
            becomes_rotten(grid, x-1, y, gridSize, gridColSize[0], &count_rot_orange, rot_orange_index);
            becomes_rotten(grid, x+1, y, gridSize, gridColSize[0], &count_rot_orange, rot_orange_index);
            becomes_rotten(grid, x, y-1, gridSize, gridColSize[0], &count_rot_orange, rot_orange_index);
            becomes_rotten(grid, x, y+1, gridSize, gridColSize[0], &count_rot_orange, rot_orange_index);
            x_round = round_times;
        }
        if (round_times < count_rot_orange) {
            count_current_rot_times++;
        }
    }

    if (count_rot_orange == total_orange) return count_current_rot_times;
    else if (count_rot_orange < total_orange) return -1;
    
    return count_current_rot_times;
}