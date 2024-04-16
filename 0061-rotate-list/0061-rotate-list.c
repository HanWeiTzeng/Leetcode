/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next) return head;
    struct ListNode *ptr1 = head, *ptr2 = head, *tmp;
    int a = 0;
    while (ptr1) {
        a++;
        ptr1 = ptr1->next;
    }
    ptr1 = head;
    if (k % a == 0) return head;
    while((k--)%a) {
        ptr2 = ptr2->next;
    }
    while(ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    tmp = ptr1->next;
    ptr1->next = NULL;
    ptr2->next = head;
    return tmp;

}