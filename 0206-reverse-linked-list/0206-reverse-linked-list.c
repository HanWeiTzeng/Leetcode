/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // 命名地不好，可以思考: prev, curr ，然後預設NULL 跟head給他們

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* ptr1 = head, *ptr2 = head->next;
    while (ptr2 != NULL) {
        if (ptr1 == head) {
            ptr1->next = NULL;
        }
        struct ListNode *tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = tmp;
    }
    return ptr1;
}
/*
============================
官方:
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* prev = NULL, *curr = head;
    while (curr != NULL) {
        struct ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}
*/