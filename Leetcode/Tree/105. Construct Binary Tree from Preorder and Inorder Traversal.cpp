//105. Construct Binary Tree from Preorder and Inorder Traversal
//TC - O(N); where N number of nodes in the tree
//SC - O(N)
class Solution{
public:
    TreeNode* generateTree(vector<int>& preorder, vector<int>& inorder, int L, int R, int &pos, unordered_map<int,int> &mp){
        if(L > R) return NULL;
        auto currRoot = new TreeNode(preorder[pos++]);
        int M = mp[currRoot->val];
        currRoot ->left = generateTree(preorder, inorder, L, M-1, pos, mp);
        currRoot->right = generateTree(preorder, inorder, M+1, R, pos, mp);
        return currRoot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int pos = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return generateTree(preorder, inorder, 0, preorder.size() - 1, pos, mp);
    }
};
