struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // check if list1/list2 is NULL, yes return another
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    struct ListNode *head = NULL, *rh;
    // check the first node of list1 if bigger than first node of list2
    while(list1 != NULL && list2 != NULL) {
        if (head == NULL) {
            if (list1->val <= list2->val) {
                head = list1;
                list1 = list1->next;
            } else {
                head = list2;
                list2 = list2->next;
            }
            rh = head;
    // yes, than check second node of list1 with first node of list2
    // no, check second node of list2 with first node of list1
        } else {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
                head = head->next;
            } else {
                head->next = list2;
                list2 = list2->next;
                head = head->next;
            }
        }
    }

    // deal with the rest of list1/list2.
    if (list1 == NULL && list2 != NULL) {
        head->next = list2; 
    } else if (list2 == NULL && list1 != NULL) {
        head->next = list1;         
    }
    return rh;
}