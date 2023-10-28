class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* before = NULL;
        while(head != NULL){
            ListNode* after = head->next;
            head->next = before;
            before = head;
            head = after;
        } 
        return before;
    }
};