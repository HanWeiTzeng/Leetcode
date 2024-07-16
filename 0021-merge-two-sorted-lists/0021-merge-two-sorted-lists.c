/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Handle list1 and list2 == NULL
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // create a new head
    struct ListNode* head = NULL;
    struct ListNode* ret_head = NULL;
    struct ListNode* dummy_node = malloc(sizeof(struct ListNode));
    head = dummy_node;
    ret_head = dummy_node;

    // continue to compare list1 and list2
    // break while loop if list1 == NULL or list2 == NULL
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            head->next = list1; // 1
            list1 = list1->next;
        } else {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }
    // add the rest of list1 or list2
    if (list1) {
        head->next = list1;
    } else {
        head->next = list2;
    }
    return ret_head->next;
}