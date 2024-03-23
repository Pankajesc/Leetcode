class Solution {
public:
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode* dummy = head;
        stack <ListNode*> nodes;
        while (dummy != NULL) {
            nodes.push(dummy);
            size++;
            dummy = dummy->next;
        }
        dummy = head;
        for (int i = 0; i < size / 2; i++) {
            ListNode* temp = dummy->next;
            dummy->next = nodes.top();
            nodes.pop();
            dummy = dummy->next;
            dummy->next = temp;
            dummy = temp;
        }
        dummy->next = NULL;
    }
};