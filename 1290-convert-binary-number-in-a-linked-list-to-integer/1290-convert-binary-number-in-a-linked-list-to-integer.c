/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int ret_val = 0;
    struct ListNode* node = head;
    while(node) {
        if (node != head) {
            ret_val *= 2;
        }
        ret_val += node->val;
        node = node->next;
    }
    return ret_val;
}