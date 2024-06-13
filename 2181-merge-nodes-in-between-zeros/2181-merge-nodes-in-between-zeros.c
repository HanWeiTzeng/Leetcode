/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void mergenode(struct ListNode* node1, struct ListNode* node2) {
    // add value into node1
    node1->val = node1->val + node2->val;
    // update node.
    struct ListNode* freenode = node2;
    node1->next = node2->next;
    free(freenode);
    //return node1;
}

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* first = head;
    struct ListNode* second = head->next;
    struct ListNode* rm_node = head;
    while (second) {
        // search 1st 0 and second search 2nd 0
        if (first->val != 0) {
            printf("Error coding!\n");
        }
        while (second->val != 0) {
            second = second->next;
        }
        // merge first->next with next until encounter 0.
        while (first->next != second) {
            mergenode(first, first->next);
        }
        // update first to second, second = second->next;
        rm_node = first;
        first = second;
        second = second->next;
        // end if second encounter NULL.
    }
    mergenode(rm_node ,first);
    // return head.
    return head;
}