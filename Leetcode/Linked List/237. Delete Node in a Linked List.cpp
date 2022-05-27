//237. Delete Node in a Linked List
//TC - O(1)
//SC - O(1)
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* dumpNode = node -> next;
		node -> val = dumpNode -> val;
		node -> next = dumpNode -> next;
		delete dumpNode;
	}
};
