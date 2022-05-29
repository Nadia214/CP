//Tc - O(n)
//Sc - O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
		Node* curr = head;
		while(curr)
		{
          Node* newNode = new Node(curr -> val);
		  newNode->next = curr ->next;
		  curr->next = newNode;
		  curr = newNode->next;
        }
		curr = head;
		while(curr)
		{
          if(curr -> random)
		  {
             curr->next->random = curr->random->next;
		  }
		  curr = curr->next->next;
		}
	    Node* result =  head->next;
        Node* copy = head->next;
        Node* original =head;

        while(original  && copy)
        {
           Node* curr = copy->next;
           original->next = curr;
           if(curr)
           {
             copy->next = curr->next;
           }
           original = original->next;
           copy = copy->next;
        }
        return result;
    }
};
