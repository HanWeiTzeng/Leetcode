/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct queue {
    int rear, front, size;
    unsigned capacity;
    int **array;
};

bool isFull(struct queue *queue) {
    return queue->size == queue->capacity;
}

int checkSize(struct queue *queue) {
    return queue->size;
}

bool isEmpty(struct queue *queue) {
    return queue->size == 0;
}

struct queue *create_queue(unsigned capacity) {
    struct queue *newqueue = (struct queue *)malloc(sizeof(struct queue));
    if (newqueue == NULL) {
        printf("Allocate memory failed.\n");
        return NULL;
    }
    newqueue->rear = capacity -1;
    newqueue->front = 0;
    newqueue->size = 0;
    newqueue->capacity = capacity;
    newqueue->array = (int **) malloc(sizeof(int *)*capacity);
    if (newqueue->array == NULL) {
        printf("Allocate memory failed. (array)\n");
        return NULL;
    }
    for (int i = 0; i < capacity; i++) {
        newqueue->array[i] = (int *)malloc(sizeof(int)*2);
        if (newqueue->array[i] == NULL) {
            printf("Allocate memory failed. (array)\n");
            return NULL;
        }
    }
    return newqueue;
};

void enqueue(struct queue *queue, int value1, int value2) {
    if (isFull(queue)) {
        //printf("This queue is full.(%s), %d can't not enter queue.\n",__FUNCTION__, value);
        return;
    }
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear][0] = value1;
    queue->array[queue->rear][1] = value2;
    queue->size++;
}

int *dequeue(struct queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    int *tmp = (int *)malloc(sizeof(int) * 2);
    tmp[0] = queue->array[queue->front][0];
    tmp[1] = queue->array[queue->front][1];
    queue->front = (queue->front+1) % queue->capacity;
    queue->size--;
    return tmp;
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matSize;
    *returnColumnSizes = (int *)malloc(matSize * sizeof(int));  // Allocate memory for returnColumnSizes
    int **ret_mat = (int **)malloc(sizeof(int *)* matSize);
    // prepare a queue store for 0 and 1, and so on.
    struct queue *queue = create_queue(matSize * matColSize[0]);


    for (int i = 0; i < matSize; i++) {
        ret_mat[i] = (int *) malloc(sizeof(int) * matColSize[i]);
        (*returnColumnSizes)[i] = matColSize[i];
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 0) {
                // put it into queue.
                ret_mat[i][j] = 0;
                enqueue(queue, i,j);
            } else {
                ret_mat[i][j] = INT_MAX;
            }
        }
    }

    while (isEmpty(queue) != 1) {
        int size = checkSize(queue);
        for (int i = 0; i < size; i++) {
            int *tmp = dequeue(queue);
            int x = tmp[0], y = tmp[1];

            // Enqueue valid neighbors
            if (x - 1 >= 0 && ret_mat[x - 1][y] == INT_MAX) {
                ret_mat[x - 1][y] = ret_mat[x][y] + 1;
                enqueue(queue, x - 1, y);
            }
            if (x + 1 < matSize && ret_mat[x + 1][y] == INT_MAX) {
                ret_mat[x + 1][y] = ret_mat[x][y] + 1;
                enqueue(queue, x + 1, y);
            }
            if (y - 1 >= 0 && ret_mat[x][y - 1] == INT_MAX) {
                ret_mat[x][y - 1] = ret_mat[x][y] + 1;
                enqueue(queue, x, y - 1);
            }
            if (y + 1 < matColSize[x] && ret_mat[x][y + 1] == INT_MAX) {
                ret_mat[x][y + 1] = ret_mat[x][y] + 1;
                enqueue(queue, x, y + 1);
            }
            free(tmp); // Free the temporary storage // Here!
        }
    }
    return ret_mat;
}