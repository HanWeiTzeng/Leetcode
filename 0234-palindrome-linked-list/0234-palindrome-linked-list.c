/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse_ll_fun(struct ListNode* head) {
    /*if (head == NULL || head->next == NULL) {
        return head ;
    }
    */
    struct ListNode* pre = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    return pre;
}
bool isPalindrome(struct ListNode* head) {
    // use slow/fast and reverse the first
    if (head == NULL || head->next == NULL) {
        return true;
    }
    int number_of_node = 0;
    struct ListNode* runner = head;
    while (runner != NULL) {
        number_of_node++;
        runner = runner->next;
    }
    // deal with odd numbers and even
    printf("number_of_node %d\n", number_of_node);
    struct ListNode* reverse_ll = head;
    int reverse_count = (number_of_node+1)/2;
    while (reverse_count != 0) {
        reverse_ll = reverse_ll->next;
        reverse_count--;
    }
    reverse_ll = reverse_ll_fun(reverse_ll);
    // cmp them.
    while (reverse_ll != NULL) {
        printf("%d %d\n", reverse_ll->val, head->val);
        if (reverse_ll->val != head->val) {
            return false;
        }
        reverse_ll = reverse_ll->next;
        head = head->next;
    }
    return true;
}