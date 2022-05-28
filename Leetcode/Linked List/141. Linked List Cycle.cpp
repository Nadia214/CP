//141. Linked List Cycle
//Time Complexity : O(N)
//Space Complexity : O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        auto tortoise = head;
        auto rabbit = head;
        while(rabbit && rabbit->next)
        {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            if(tortoise == rabbit)
            {
                return true;
            }
        }
        return false;
    }
};

