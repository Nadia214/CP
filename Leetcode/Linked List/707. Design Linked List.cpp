//707. Design Linked List
//N - Total number of nodes created in memory
//TC - get: O(n), addAtHead: O(1), addAtTail: O(n), addAtIndex: O(n), deleteAtIndex: O(n)
//SC -O(N)
class MyLinkedList {
public:
    class linkedListNode{
    public:
        int value;
        linkedListNode* next;
        linkedListNode(int val, linkedListNode* nxt){
            value = val;
            next = nxt;
        }
    };

    linkedListNode* head;
    int DUMMYVALUE = INT_MIN;
    MyLinkedList() {
        head = new linkedListNode(DUMMYVALUE, NULL);
    }

    int get(int index) {
        linkedListNode* currNode = head;
        index++;
        while(index && currNode->next){
            currNode = currNode->next;
            index--;
        }
        if(index == 0){
            return currNode->value;
        }
        return -1;
    }

    void addAtHead(int val) {
        addAtIndex(0,val);
    }

    void addAtTail(int val) {
        linkedListNode* currNode = head;

        while(currNode ->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = new linkedListNode(val, NULL);
    }

    void addAtIndex(int index, int val) {
        linkedListNode* currNode = head;

        while(index && currNode->next){
            currNode = currNode->next;
            index--;
        }
        if(index == 0){
            currNode->next = new linkedListNode(val, currNode->next);
        }

    }

    void deleteAtIndex(int index) {
        linkedListNode* currNode = head;

        while(index && currNode->next && currNode->next->next){
            currNode = currNode->next;
            index--;
        }

        if(index == 0){
            auto dumpNode = currNode->next;
            currNode ->next = currNode->next->next;
            delete(dumpNode);
        }

    }
};
