/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    // use recursive and find biggest.
    if (head == NULL) return NULL;
    struct ListNode* biggest_node = head;
    while (head) {
        if (head->val > biggest_node->val) {
            biggest_node = head;
        }
        head = head->next;
    }
    biggest_node->next = removeNodes(biggest_node->next);
    return biggest_node;
}