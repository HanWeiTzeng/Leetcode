/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    // create new pointer
    struct ListNode* ret_list = head;
    struct ListNode* check_node = head;
    struct ListNode* tmp = NULL;
    while (check_node != NULL) {
        tmp = check_node->next;
        if (ret_list == check_node) {
            ret_list->next = NULL;
        } else {
            check_node->next = ret_list;
            ret_list = check_node;
        }
        check_node = tmp;
    }
    return ret_list;
}