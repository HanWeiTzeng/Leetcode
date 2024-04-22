/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /* 可以用hashtable存，全部的ListA node address 然後依序遍歷ListB's Node*/
 /* 下面方式可以用這特殊方法，hint: 错的人就算走过了对方的路也还是会错过*/
 /* 只要是对的人，就算开始错过了，最终还是会再次相遇在一起的。*/
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        if (pa != NULL) {
            pa = pa->next;
        } else {
            pa = headB;
        }
        if (pb != NULL) {
            pb = pb->next;
        } else {
            pb = headA;
        }
    }
    return pa;
}