//206. Reverse Linked List
//Time Complexity : O(N) where N = total number of Nodes
//Space Complexity : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        auto curr = head;
        ListNode* prev = NULL;
        while(curr)
        {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        return prev;
    }
}
