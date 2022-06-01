//2. Add Two Numbers
//TC - O(N) where N  = total number of Nodes in the list
//SC - O(N)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0), *tail = head;
        while (l1 || l2 || carry) {
            int digit1,digit2;
            if (l1) {
                digit1 = l1->val;
                l1 = l1->next;
            }
            else
                digit1 = 0;

            if (l2) {
                digit2 = l2->val;
                l2 = l2->next;
            }
            else
                digit2 = 0;

            int temp = digit1 + digit2 +carry;
            tail->next = new ListNode(temp%10);
            tail = tail->next;
            carry = temp/10;

        }

        return head->next;
    }
};
