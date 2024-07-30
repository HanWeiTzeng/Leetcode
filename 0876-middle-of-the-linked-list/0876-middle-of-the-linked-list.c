/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    // use first/ slow pointer.
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast != NULL) {
        slow = slow->next;  // 1 2 3 
        fast = fast->next;  // 2 3 4  5 null
        if (fast && fast->next != NULL) {
            fast = fast->next;  // 2->3 4 5 null
        } else {
            break;
        }
    }
    return slow;
}