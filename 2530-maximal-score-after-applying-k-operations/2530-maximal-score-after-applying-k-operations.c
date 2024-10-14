
// A structure to represent a Max-Heap (Priority Queue)
typedef struct {
    int size;
    int *data;
} MaxHeap;

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Heapify the node at index i in the heap of size n
void heapify(MaxHeap *heap, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }

    // If largest is not root, swap it and continue heapifying
    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        heapify(heap, largest);
    }
}

// Insert a new value into the priority queue
void insert(MaxHeap *heap, int value) {
    // Insert new value at the end of the heap
    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = value;

    // Fix the max heap property if it's violated
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        swap(&heap->data[(i - 1) / 2], &heap->data[i]);
        i = (i - 1) / 2;
    }
}

// Remove and return the element with the highest priority
void extractMax(MaxHeap *heap) {
    // remove it from the heap
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    // Heapify the root
    heapify(heap, 0);

    return;
}

long long maxKelements(int* nums, int numsSize, int k) {
    // declare a return value.
    long long ret_val = 0;
    MaxHeap heap;
    heap.size = 0;
    heap.data = (int *)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        insert(&heap, nums[i]);
    }

    for (int i = 0; i < k; i++) {
        int new_value = heap.data[0] / 3;
        ret_val += heap.data[0];
        if (new_value * 3 != heap.data[0])
            new_value++;
        extractMax(&heap);
        insert(&heap, new_value);
    }

    return ret_val;
}