/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    // use 2 node 1 for a, 1 for b
    struct ListNode* a_node = list1;
    struct ListNode* b_node = list1;
    for (int i = 0; i < a-1; i++) {
        a_node = a_node->next;
        b_node = b_node->next;
    }
    for (int i = 0; i < b-a+1+1; i++) {
        b_node = b_node->next;
    }
    // no considering free.
    // a->next = list2.
    a_node->next = list2;
    while (list2->next) {
        list2 = list2->next;
    }
    // last one of list2 -> b
    list2->next = b_node;
    return list1;
}