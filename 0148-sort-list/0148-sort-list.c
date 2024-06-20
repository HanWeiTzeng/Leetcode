struct ListNode* sortedmerge(struct ListNode* first, struct ListNode* second);

void divid_ll(struct ListNode* head, struct ListNode** first, struct ListNode** second) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

void mergesort(struct ListNode** refhead) {
    struct ListNode* head = *refhead;
    struct ListNode* first;
    struct ListNode* second;
    if (head == NULL || head->next == NULL) return;
    divid_ll(head, &first, &second);
    mergesort(&first);
    mergesort(&second);
    *refhead = sortedmerge(first, second);
}

struct ListNode* sortedmerge(struct ListNode* first, struct ListNode* second) {
    struct ListNode* result = NULL;
    if (first == NULL) return second;
    if (second == NULL) return first;
    if (first->val <= second->val) {
        result = first;
        result->next = sortedmerge(first->next, second);
    } else {
        result = second;
        result->next = sortedmerge(first, second->next);
    }
    return result;
}

struct ListNode* sortList(struct ListNode* head) {
    mergesort(&head);
    return head;
}