//104. Maximum Depth of Binary Tree
//TC - O(N) ; N = number of nodes
//SC - O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()) {
            depth++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto parentNode = q.front();
                q.pop();
                if(parentNode -> left) q.push(parentNode ->left);
                if(parentNode -> right) q.push(parentNode -> right);
            }
        }
        return depth;
    }
};
