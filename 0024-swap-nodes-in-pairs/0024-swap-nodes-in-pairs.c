/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* ptr1 = head, *ptr2 = head->next, *tmp = NULL;
    
    while (ptr2) {
        if (ptr1 == head) {
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            head = ptr2;
        } else {
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            tmp->next = ptr2;
        }
        if (ptr1->next != NULL) {
            tmp = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr1->next;
        } else {
            ptr2 = NULL;
        }
    }
    return head;
}