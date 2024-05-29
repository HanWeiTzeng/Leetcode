/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse_linked_list(struct ListNode* head) {
    struct ListNode* pre = head;
    struct ListNode* curr = head;
    while (curr) {
        if (curr == head) {
            struct ListNode* tmp = curr->next;
            curr->next = NULL;
            curr = tmp;
        } else {
            struct ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
    }
    return pre;
}

int pairSum(struct ListNode* head) {
    int num_of_node = 0;
    struct ListNode* first = head;
    struct ListNode* second = head;
    while (second) {
        num_of_node += 2;
        first = first->next;
        second = second->next->next;
    }
    first = reverse_linked_list(first);
    int max = first->val + head->val;
    while (first) {
        //printf("first = %d.\n", first->val);
        if (first->val + head->val > max) {
            max = first->val + head->val;
        }
        first = first->next;
        head = head->next;
    }
    return max;
}