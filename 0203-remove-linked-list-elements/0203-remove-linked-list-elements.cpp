class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      if(head==nullptr) return head;
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr=head;
        ListNode* prev = head;
        while(curr!=nullptr){
            if(curr->val==val){
               
			prev->next=curr->next;
			curr=curr->next;

            }
            else{
                prev=curr;
                curr= curr->next;
            }
        }
        return head;
    }
};