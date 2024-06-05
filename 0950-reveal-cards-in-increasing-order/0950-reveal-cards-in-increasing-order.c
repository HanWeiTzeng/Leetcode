/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct linked_list {
    int val;
    struct linked_list *next;
};
struct queue {
    struct linked_list *front;
    struct linked_list *rear;
};

struct queue *create_queue();
void enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
void show_queue(struct queue *queue);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    *returnSize = deckSize;
    int count = 0;
    mergeSort(deck, 0, deckSize-1);
    struct queue *idx_queue = create_queue();
    for (int i = 0; i < deckSize; i++) {
        enqueue(idx_queue, i);
    }
    //show_queue(idx_queue);
    int i = 0;
    int *ret_arr = (int *)malloc(sizeof(int)*deckSize);
    while (idx_queue->front && i < deckSize) {
        show_queue(idx_queue);
        //printf("idx_queue->front->val %d i = %d",idx_queue->front->val, i);
        ret_arr[idx_queue->front->val] =  deck[i++];
        idx_queue->front = idx_queue->front->next;
        int tmp = dequeue(idx_queue);
        enqueue(idx_queue, tmp);
    }
    return ret_arr;
}

struct queue *create_queue() {
    struct queue *newqueue = (struct queue *)malloc(sizeof(struct queue));
    if (!newqueue) return NULL;
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
}
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the allocated memory
    free(L);
    free(R);
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

struct linked_list *create_node(int value) {
    struct linked_list *newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
    if(!newnode) return NULL;
    newnode->val = value;
    newnode->next = NULL;
    return newnode;
}

void enqueue(struct queue *queue, int value) {
    if (!queue) return;
    struct linked_list *node = create_node(value);
    if (queue->front == NULL) {
        queue->rear = node;
        queue->front = node;
    } else {
        queue->rear->next = node;
        queue->rear = queue->rear->next;
    }
    return;
}
int dequeue(struct queue *queue) {
    if (queue->front == NULL) {
        printf("This queue is empty.\n");
        return -1;
    }

    struct linked_list *node = queue->front;
    int tmp = queue->front->val;
    // only one node in queue.
    if (queue->front == queue->rear) {
        queue->rear = NULL;
    }
    queue->front = queue->front->next;
    free(node);
    return tmp;
}
void show_queue(struct queue *queue) {
    if (queue->front == NULL) {
        printf("this queue is empty.\n");
        return;
    }
    struct linked_list *node = queue->front;
    while(node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
    return;
}