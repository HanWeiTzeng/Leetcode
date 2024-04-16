/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL|| head->next == NULL) return head;

    struct ListNode* midnode = head, *endnode = head->next;
    while (endnode != NULL) {
        midnode = midnode->next;
        endnode = endnode->next;
        if (endnode) endnode = endnode->next;
    }
    return midnode;
}
/*
=====================

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fast = head, *slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast ->next ->next;
    }
    return slow;
}
作者：糗菇凉
链接：https://leetcode.cn/problems/middle-of-the-linked-list/solutions/2105939/lian-biao-de-zhong-jian-jie-dian-by-qiu-kl0rd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/