/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 **/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // index 0 is 10^0, next-node is 10^1
    // need to have a carry
    int carry = 0;
    struct ListNode *ret, *prev_new_list = NULL;
    if (l1 != NULL) ret = l1;
        else ret = l2;

    while (l1 != NULL && l2 != NULL) {
        l1->val += l2->val + carry;
        carry = (l1->val)/10;   //update carry
        l1->val %= 10;          //update node val
        prev_new_list = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    // while l1 or l2 is null, while loop stop
    if (l2 != NULL) prev_new_list->next = l2;

    // then use carry to count the rest of node.
    while (carry != 0 && prev_new_list->next != NULL) {
        prev_new_list = prev_new_list->next;  // original node has calculated. 
        prev_new_list->val += carry;
        carry = prev_new_list->val/10;
        prev_new_list->val %= 10;
    }

    if (carry != 0 && prev_new_list->next == NULL) {
        struct ListNode *newnode;
        newnode = (struct ListNode *) malloc(sizeof(struct ListNode));
        prev_new_list->next = newnode;
        prev_new_list = prev_new_list->next;
        prev_new_list->val = 1;
        prev_new_list->next = NULL;
    }

    return ret;

}