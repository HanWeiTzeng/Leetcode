/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *tmp = node;
    while (node->next) {
        node->val = node->next->val;
        //printf("%d",node->val);
        tmp = node;
        node = node->next;
    }
    tmp->next = NULL;
    free(node);
}