


typedef struct {
    int top;
    int capacity;
    int *array;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack* newstack = (CustomStack* ) malloc(sizeof(CustomStack));
    if (!newstack) {
        printf("Allocate memory failed.\n");
        return NULL;
    }
    newstack->top = -1;
    newstack->capacity = maxSize;
    newstack->array = (int *)malloc(sizeof(int)*maxSize);
    if (!newstack->array) {
        printf("Allocate memory failed.\n");
        return NULL;
    }
    return newstack;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top == obj->capacity-1) return;
    obj->array[++obj->top] = x;
    return;
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1) return -1;
    return obj->array[obj->top--];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if (obj->top == -1) {
        return;
    }
    for (int i = 0; i < k && i <= obj->top; i++) {
        obj->array[i] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/