//2130. Maximum Twin Sum of a Linked List
//TC - O(N) where N is the total number of nodes.
//SC - O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextT;
        }

        int res = 0;
        while(prev){
            res=max(res, prev->val + head->val);
            prev=prev->next;
            head=head->next;
        }
        return res;
    }
};
