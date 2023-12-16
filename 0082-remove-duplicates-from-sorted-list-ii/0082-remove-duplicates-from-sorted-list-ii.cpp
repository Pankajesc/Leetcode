class Solution {
public:
    void solve(ListNode* head,ListNode* tail,int count){
        ListNode* newnode  = new  ListNode(head->val);

        if(head->next == NULL) {
            if(head->val != INT_MIN) tail->next = newnode;
            return;
        }
        
          ListNode* temp = head;
          while(temp ->next != NULL){
              temp = temp->next;
              if( head->val != INT_MIN && head->val == temp->val){
                  temp->val = INT_MIN;
                  count++;
              }
              if(temp ->next == NULL &&  head->val != INT_MIN && head->val == temp->val){
                temp->val = INT_MIN;
                  count++;
              }
          }
          
          if(count == 1 && head->val != INT_MIN){
              tail->next = newnode; tail = newnode; 
          }
          solve(head->next,tail,1);
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL ) return NULL;
        ListNode* newlist = new  ListNode();
        solve(head,newlist,1);
        return newlist->next;
    }
};