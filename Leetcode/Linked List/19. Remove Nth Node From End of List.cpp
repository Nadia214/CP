//19. Remove Nth Node From End of List
//Time Complexity : O(N)
//Space Complexity : O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i<n; i++)
        {
            fast = fast->next;

        }
        if(!fast)return head->next;

        while(fast->next)
        {
            fast = fast ->next;
            slow = slow -> next;
        }
        slow -> next = slow->next->next;

        return head;
    }
};
