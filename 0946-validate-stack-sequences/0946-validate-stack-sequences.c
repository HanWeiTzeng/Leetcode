bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stack[pushedSize];
    int top = -1;
    int push_idx = 0;
    int pop_idx = 0;
    while (pop_idx < poppedSize) {
        if (top >= 0 && stack[top] == popped[pop_idx]) {
            top--;
            pop_idx++;
        } else if (push_idx == pushedSize) {
            return false;
        } else if (pushed[push_idx] == popped[pop_idx]) {
            pop_idx++;
            push_idx++;
        } else if (pushed[push_idx] != popped[pop_idx]) {
            stack[++top] = pushed[push_idx];
            push_idx++;
        }
    }
    return true;
}