class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *curr=head, *prev=dummy, *next;
        int length = 0;
        for(ListNode* temp = head; temp != NULL; temp=temp->next) length++;

        for(int i = 0 ; i < length/k; i++) {
            curr = prev->next;
            next = curr->next;
            for(int j = 0 ; j < k-1; j++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
        }
        return dummy->next;
    }
};