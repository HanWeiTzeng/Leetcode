/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoSortedList(struct ListNode* list1, struct ListNode* list2) {
    //if (list1 == NULL && list2 == NULL) return NULL;
    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* dummy = head;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            head->next = list1;
            list1 = list1->next;
        } else {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }

    if (list1 != NULL) {
        head->next = list1;
    } else {
        head->next = list2;
    }
    return dummy->next;
}
 struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    //merge list into list[0];
    int i = 1;
    while (i < listsSize) {
        lists[0] = mergeTwoSortedList(lists[0], lists[i]);
        i++;
    }
    return lists[0];
}
/*
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
*/