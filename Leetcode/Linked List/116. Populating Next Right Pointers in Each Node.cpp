//116. Populating Next Right Pointers in Each Node
//SC- O(N)
//TC -O(1)
class Solution {
public:
    Node* connect(Node* root){
        if(root == NULL)return NULL;
        Node *level = root;
        while (level)
        {
            Node* curr = level;
            while (curr && curr->left)
            {
                curr->left->next = curr->right;
                if (curr -> next)
                {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            level = level -> left;
        }
        return root;
    }
};
