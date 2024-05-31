/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    int idx = 0;
    int null_flag = 1;
    struct ListNode* head = lists[0];    // use 1st node, and set it as head in default.

    // check all the first node in K lists.
    for (int i = 0; i < listsSize; i++) {
        //need to handle NULL pointer
        if (lists[i] != NULL) {
            null_flag = 0;
            if (head == NULL || head->val > lists[i]->val) {
                head = lists[i];
                idx = i;
            }
        }
    }
    if (lists[idx] != NULL)
    lists[idx] = lists[idx]->next;
    if (null_flag == 0)
    head->next = mergeKLists(lists, listsSize);
    return head;
}