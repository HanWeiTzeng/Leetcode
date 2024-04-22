/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        if (head->val == val) {
            free(head);
            return NULL;
        } else {
            return head;
        }
    }
    struct ListNode* pre = head;
    struct ListNode* curr = head->next;
    while (curr) {
        if (pre->val == val) {
            free(pre);
            pre = curr;
            head = pre;
            curr = curr->next;
            if (curr == NULL && pre->val == val) {
                free(pre);
                return NULL;
            }
        } else {
            if (curr->val != val) {
                pre = curr;
                curr = curr->next;
            } else {
                pre->next = curr->next;
                free(curr);
                curr = pre->next;
            }
        }
    }
    return head;
}