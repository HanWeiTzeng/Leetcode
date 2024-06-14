/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* tmp;
    while (curr) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
    // reverse node.
    struct ListNode* dummynode = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummynode->val = 0;
    dummynode->next = reverse(head);
    struct ListNode* ret_listnode = dummynode;
    struct ListNode* trav_listnode = ret_listnode;
    struct ListNode* tmp;
    int max = ret_listnode->val;

    // keep the max value, and use it to judge.
    while (trav_listnode) {
        tmp = trav_listnode->next;
        if (max > trav_listnode->val) { // 8 8
            free(trav_listnode);
        } else if (max <= trav_listnode->val) {
            max = trav_listnode->val;
            dummynode->next = trav_listnode;
            dummynode = dummynode->next;
        }
        trav_listnode = tmp;
    }
    dummynode->next = NULL;
    tmp = ret_listnode;
    ret_listnode = ret_listnode->next;
    free(tmp);
    ret_listnode = reverse(ret_listnode);
    return ret_listnode;
}