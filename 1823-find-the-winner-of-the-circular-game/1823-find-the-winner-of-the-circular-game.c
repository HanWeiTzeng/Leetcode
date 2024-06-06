struct linked_list {
    int val;
    struct linked_list *next;
};

struct queue {
    struct linked_list *front;
    struct linked_list *rear;
};

struct queue *create_queue(void);
struct linked_list *create_node(int value);
void enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
void display_queue(struct queue *queue);

int findTheWinner(int n, int k) {
    // create a linked list queue with n node.
    struct queue *table_queue = create_queue();
    int table_people_num = n;
    // it need to be circular queue
    for (int i = 1; i <= n; i++) {
        enqueue(table_queue, i);
    }
    //display_queue(table_queue);

    for (int i = 1; i <= n-1; i++) {
        int count = k;  // 2
        while (count > 1) {
            table_queue->front = table_queue->front->next;
            table_queue->rear = table_queue->rear->next;
            count--;
        }
        dequeue(table_queue);
        //printf("Dequeue: %d ", dequeue(table_queue));
        //display_queue(table_queue);
    }

    return dequeue(table_queue);
    // return it when node number is 1
}


void enqueue(struct queue *queue, int value) {
    struct linked_list *node = create_node(value);
    if (queue->rear == NULL) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->rear->next = queue->front;    //circular queue
    return;
}

int dequeue(struct queue *queue) {
    if (queue->front == NULL) {
        printf("This queue is empty.\n");
        return INT_MIN;
    }
    int ret_val = queue->front->val;

    struct linked_list *tmpnode = queue->front;
    if (queue->front == queue->rear) {
        queue->rear = NULL;
        queue->front = NULL;
        //queue->rear = queue->rear->next; // i.e queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }
    free(tmpnode);
    return ret_val;
}

struct queue *create_queue(void) {
    struct queue *newqueue = (struct queue *)malloc(sizeof(struct queue));
    if (!newqueue) {
        printf("Allocate memory failed.\n");
        return NULL;
    }
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
};

struct linked_list *create_node(int value) {
    struct linked_list *newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
    if (!newnode) {
        printf("Allocate memory failed.\n");
        return NULL;
    }
    newnode->val = value;
    newnode->next = NULL;
    return newnode;
}

void display_queue(struct queue *queue) {
    struct linked_list *tmpnode = queue->front;
    printf("The queue is: ");
    while (tmpnode != queue->rear) {
        printf("%d ", tmpnode->val);
        tmpnode = tmpnode->next;
    }
    printf("%d ", tmpnode->val);
    printf("\n");
}