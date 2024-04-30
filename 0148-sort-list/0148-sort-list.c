/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void divide_ll(struct ListNode* head, struct ListNode** a, struct ListNode** b) {
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
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

void mergesort(struct ListNode** refhead) {
    struct ListNode* first;
    struct ListNode* second;
    struct ListNode* head = *refhead;
    if (head == NULL || head->next == NULL) return;

    divide_ll(head, &first, &second);
    mergesort(&first);
    mergesort(&second);
    *refhead = sortedmerge(first, second);
}


struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* newhead = head;
    mergesort(&head);
    return head;
}