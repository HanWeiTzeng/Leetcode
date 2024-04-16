/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //#include <stdlib.h>
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (!head) return head;
    else if (n == 1 && !(head->next)) {
        free(head);
        return NULL;
    }

    struct ListNode *detect_ptr = head;
    struct ListNode *post_detect_ptr = head;

    while(n--) {
        post_detect_ptr = post_detect_ptr->next;
    }

    while (post_detect_ptr != NULL && post_detect_ptr->next != NULL) {
        detect_ptr = detect_ptr->next;
        post_detect_ptr = post_detect_ptr->next;
    }

    if (n == 1) {
        free(detect_ptr->next);
        detect_ptr->next = NULL;
        return head;
    }

    if (!post_detect_ptr) {
        head = head->next;
        free(detect_ptr);
        return head;
    }

    post_detect_ptr = detect_ptr->next;
    detect_ptr->next = detect_ptr->next->next;
    free(post_detect_ptr);

    return head;
}