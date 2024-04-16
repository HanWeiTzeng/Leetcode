/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//  1. 可以用矩陣存下來
//  2. 翻轉整個記下來
//  3. 直接翻轉原本的一半(還不會)

//  ====================
//  第一版
bool isPalindrome(struct ListNode* head) {
    if (head->next == NULL) return head;

    struct ListNode *revNode_final;
    struct ListNode *node1 = head, *node2 = head;
    while (node1 != NULL) {
        if (node1 == head) {
            struct ListNode *revNode;
            revNode = malloc(sizeof(struct ListNode));
            revNode->val = node1->val;
            revNode->next = NULL;
            revNode_final = revNode;
        } else {
            struct ListNode *addNode;
            addNode = malloc(sizeof(struct ListNode));
            addNode->val = node1->val;
            addNode->next = revNode_final;
            revNode_final = addNode;
        }
        node1 = node1->next;
    }

    while(revNode_final != NULL && node2 != NULL) {
        if(revNode_final->val != node2->val) return false;
        revNode_final = revNode_final->next;
        node2 = node2->next;
    }
    return true;
}