/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // use fast and slower pointer
    if (head == NULL) return false;
    struct ListNode *slower = head;
    struct ListNode *faster = head->next;
    while (slower && faster) {
        if (slower == faster) {
            return true;
        } else {
            slower = slower->next;
            faster = faster->next;
            if (faster == NULL) {
                return false;
            }
            faster = faster->next;
        }
    }
    return false;
}