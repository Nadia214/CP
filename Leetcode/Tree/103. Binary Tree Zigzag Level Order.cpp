//103. Binary Tree Zigzag Level Order
//TC : O(N), N is number of nodes in the tree
//SC : O(n) for result vector
Time:
O(n)
class Solution {
public:
    void getOrder(TreeNode*root, vector<vector<int>>& result, int level){
        if(!root) return;
        if(level >= result.size())
            result.push_back({});
        result[level].push_back(root->val);
        getOrder(root->left, result, level+1);
        getOrder(root->right, result, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>>result;
        if(!root) return result;
        getOrder(root, result, 0);

        for(int i = 1; i < result.size(); i = i + 2){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
