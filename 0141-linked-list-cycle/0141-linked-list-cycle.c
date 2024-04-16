/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 注意：查cycle -> two pointer ->1 個走一步 2個走兩步

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    // Two pointer
    struct ListNode *ptr1st = head, *ptr2nd = head->next;

    while (ptr1st != ptr2nd) {
        if (ptr1st != NULL) {          /// 這邊不用留
            ptr1st = ptr1st->next;
        } else return false;
        if (ptr2nd != NULL && ptr2nd->next != NULL) {
            ptr2nd = ptr2nd->next->next;
        } else return false;
    }
    // it has cycle if it breaks while loop;
    return true;
}