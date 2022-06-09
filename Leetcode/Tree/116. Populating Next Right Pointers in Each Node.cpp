//116. Populating Next Right Pointers in Each Node
//SC- O(N), where N is the number of nodes in a tree
//TC -O(n)
class Solution{
public:
    Node* connect(Node* root){
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* rightNode = NULL;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto curr = q.front();
                q.pop();
                curr -> next = rightNode;
                rightNode = curr;
                if(curr -> right){
                    q.push(curr -> right);
                    q.push(curr -> left);
                }
            }
        }
    return root;
    }
};
