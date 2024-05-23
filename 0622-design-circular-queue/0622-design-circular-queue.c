


typedef struct {
    int front, rear, size;
    unsigned capacity;
    int *array;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* newQueue = (MyCircularQueue*) malloc(sizeof(MyCircularQueue)*k);
    if (!newQueue) {
        printf("Allocate memory failed.\n");
    }
    newQueue->front = 0;
    newQueue->rear = k-1;
    newQueue->size = 0;
    newQueue->capacity = k;
    newQueue->array = (int *) malloc(sizeof(int)*k);
    if (!newQueue->array) {
        printf("Allocate memory failed.\n");
    }
    return newQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->rear = (obj->rear+1) % obj->capacity;
    obj->array[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) return false;
    obj->array[obj->front];
    obj->front = (obj->front+1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->array[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->array[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/