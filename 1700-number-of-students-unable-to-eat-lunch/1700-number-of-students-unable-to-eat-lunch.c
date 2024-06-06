void show_queue(int *students, int studentsSize, int front, int rear) {
    printf("students: front %d rear %d\n", front, rear);
    while (front != rear) {
        printf("%d ", students[front]);
        front++;
        front %= studentsSize; 
    }
    printf("%d (%d)", students[front], students[rear]);
    printf("\n");
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int sum_0 = 0;
    int sum_1 = 0;
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) sum_0++;
        else sum_1++;
    }

    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            sum_0--;
            if (sum_0 < 0) return sum_1;
        }
        if (sandwiches[i] == 1) {
            sum_1--;
            if (sum_1 < 0) return sum_0;
        }
    }
    return 0;
    
    /*
    // need a reload function for student.
    // It need to keep tracking different status.
    int idx_sandwiches = 0;
    int first_student = 0, last_student = studentsSize-1;
    while (idx_sandwiches < sandwichesSize) {
        // student[0] get his food.
        if (students[first_student] == sandwiches[idx_sandwiches]) {
            idx_sandwiches++;
            first_student++;
            first_student %= (studentsSize);
        } else {
            // students[first_student] != sandwiches[idx_sandwiches]
            int repeat = first_student;
            while (students[first_student] != sandwiches[idx_sandwiches]) {
                //printf("Sandwish:");
                //show_queue(sandwiches, sandwichesSize, idx_sandwiches, sandwichesSize-1);
                show_queue(students, studentsSize, first_student, last_student);
                first_student++;
                first_student %= (studentsSize);
                last_student++;
                last_student  %= (studentsSize);
                printf("repeat = %d, first_student %d.\n", repeat, first_student);
                printf("\n");
                if (first_student == repeat) {
                    return sandwichesSize - idx_sandwiches;
                }
            }
            idx_sandwiches++;
            first_student++;
            first_student %= studentsSize;
        }
    // if not return modified studentsSize
    }
    return 0;
    // If yes, return 0.
    */
}