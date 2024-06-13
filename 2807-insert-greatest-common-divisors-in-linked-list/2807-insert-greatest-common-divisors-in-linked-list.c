/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int compare(int value1, int value2) {
    while (value1 != 0) {
        int tmp = value1;
        value1 = value2 % value1;
        value2 = tmp;
    }
    return value2;
}
struct ListNode* addnode(int data){
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newnode) return NULL;
    newnode->val = data;
    newnode->next = NULL;
    return newnode;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    if (curr == NULL) return prev;
    while (curr) {
        // create a node by compare prev and curr
        int comval = compare(prev->val, curr->val);
        struct ListNode* node = addnode(comval);
        // insert_node
        prev->next = node;
        node->next = curr;
        // update prev to curr, curr to curr->next
        prev = curr;
        curr = curr->next;
    }
    return head;
}