class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //BASE CASE
        if(head->next == nullptr) return true;

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;

        // Finding Mid Using 2 pointer approach
        // Reversing the first half of linked list
        while(fast && fast->next != NULL){
            head = head->next;
            fast = fast->next->next;
            slow->next = prev;
            prev = slow;
            slow = head;
        }

        // If the length of linked list is odd
        if(fast != NULL){
            head = head->next;
        } 

        // Checking for palindrome
        while(head != nullptr){
            if(head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }

        return true;

    }
};
