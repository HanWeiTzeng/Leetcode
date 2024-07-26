void mergeSortedArray(int* array, int head, int middle, int tail) {
    int len_a = middle - head + 1;
    int len_b = tail - middle;
    int A[len_a];
    int B[len_b];
    for (int i = 0; i < len_a; i++) {
        A[i] = array[head + i];
    }
    for (int i = 0; i < len_b; i++) {
        B[i] = array[middle + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = head;
    while (i < len_a && j < len_b) {
        if (A[i] < B[j]) {
            array[k] = A[i];
            k++;
            i++;
        } else {
            array[k] = B[j];
            k++;
            j++;
        }
    }
    while (i < len_a) {
        array[k] = A[i];
        k++;
        i++;
    }
    while (j < len_b) {
        array[k] = B[j];
        k++;
        j++;
    }
}

void mergesort(int* array, int head, int tail) {
    if (head < tail) {
        int middle = (head + tail) / 2;
        mergesort(array, head, middle);
        mergesort(array, middle + 1, tail);
        mergeSortedArray(array, head, middle, tail);
    }
}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    // arrange all seats
    //mergesort(seats, 0, seatsSize - 1);
    // then arrange all student
    //mergesort(students, 0, studentsSize - 1);
    qsort(seats, seatsSize, sizeof(int), compare);
    qsort(students, studentsSize, sizeof(int), compare);
    // cal all distance one by one.
    int count = 0;
    for (int i = 0; i < seatsSize; i++) {
        count += abs(seats[i]- students[i]);
        //printf("%d ", count);
    }
    // then add them.
    return count;
}