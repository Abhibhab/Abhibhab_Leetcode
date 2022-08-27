class Solution {
public: ListNode* swapPairs(ListNode* head) {

    if(head == NULL || (head->next ==NULL)){return head;}
    ListNode* first=head->next;
    ListNode * second=head;
    ListNode *third=head->next->next;
    first->next=second;
    second->next=swapPairs(third);
    return first;

}};