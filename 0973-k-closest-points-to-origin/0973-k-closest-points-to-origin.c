/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = k;
    *returnColumnSizes = (int *)malloc(k * sizeof(int)); 
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = pointsColSize[0];
    }
    double *distance = (double *)malloc(sizeof(double) * pointsSize);
    // cal distance for all points.
    for (int i = 0; i < pointsSize; i++) {
        double x = (double)points[i][0];
        double y = (double)points[i][1];
        distance[i] = sqrt(x*x + y*y);
    }
    // create an array for return.
    int **ret_mat = (int **)malloc(sizeof(int*) * k);
    
    // selection sort.
    double min_value;
    int min_index;
    int count = 0;

    for (int i = 0; i < k; i++) {
        min_value = distance[i];
        min_index = i;
        for (int j = i+1; j < pointsSize; j++) {
            //printf("check %d, %d. distance %lf\n", points[j][0], points[j][1], distance[j]);
            if (min_value > distance[j]) {
                min_value = distance[j];
                min_index = j;
            }
        }
        printf("min_index %d min_value %lf.\n", min_index, min_value);
        printf("Before %lf %lf.\n", distance[i], distance[min_index]);
        swap(distance+i, distance+min_index);
        printf("After %lf %lf.\n", distance[i], distance[min_index]);
        // rem to give ret_mat[i] = (int *)malloc ...
        swap_int(&points[i][0], &points[min_index][0]);
        swap_int(&points[i][1], &points[min_index][1]);
        ret_mat[i] = (int *)malloc(sizeof(int)*pointsColSize[min_index]);
        ret_mat[i][0] = points[i][0];
        ret_mat[i][1] = points[i][1];
    }
    free(distance);

    return ret_mat;
}