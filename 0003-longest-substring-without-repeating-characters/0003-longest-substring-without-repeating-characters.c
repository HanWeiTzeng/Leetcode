struct queue {
    int rear, front, size;
    unsigned capacity;
    int *array;
};

bool isFull(struct queue *queue) {
    return queue->size == queue->capacity;
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
    newqueue->array = (int *) malloc(sizeof(int)*capacity);
    if (newqueue->array == NULL) {
        printf("Allocate memory failed. (array)\n");
        return NULL;
    }
    return newqueue;
};

void enqueue(struct queue *queue, int value) {
    if (isFull(queue)) {
        printf("This queue is full.(%s), %d can't not enter queue.\n",__FUNCTION__, value);
        return;
    }
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = value;
    queue->size++;
    //printf("%d is enqueue.\n", queue->array[queue->rear]);
}

int dequeue(struct queue *queue) {
    if (isEmpty(queue)) {
        printf("This queue is empty.(%s)\n",__FUNCTION__);
        return -1;
    }
    int tmp = queue->array[queue->front];
    queue->front = (queue->front+1) % queue->capacity;
    queue->size--;
    return tmp;
}

int size(struct queue *queue) {
    return queue->size;
}
void check_and_dequeue(struct queue *queue, int value) {
    if (isEmpty(queue)) {
        //printf("This queue is empty.\n");
        return;
    }
    int tmp = queue->front;
    int count = 0;
    while (tmp <= queue->rear) {
        if (value == queue->array[tmp]) {
            // dequeue for "count" times.
            for (int i = 0; i <= count; i++)
            dequeue(queue);
        } else {
            count++;
        }
        tmp++;
    }
}

int lengthOfLongestSubstring(char* s) {
    int str_len = strlen(s);
    if (str_len <= 1) return str_len;
    int max_length = 0;
    struct queue *queue = create_queue(str_len);
    for (int i = 0; i < str_len; i++) {
        check_and_dequeue(queue, s[i]);
        enqueue(queue, s[i]);
        if (size(queue) > max_length) {
            max_length = size(queue);
        }
    }
    return max_length;
}