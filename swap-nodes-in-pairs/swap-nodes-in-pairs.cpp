class Solution {
public: ListNode* swapPairs(ListNode* head) {

    if(head == NULL || (head->next ==NULL)){return head;}
    ListNode* n = head->next;
    head->next = swapPairs(head->next->next);
    n->next = head;
    return n;

}};