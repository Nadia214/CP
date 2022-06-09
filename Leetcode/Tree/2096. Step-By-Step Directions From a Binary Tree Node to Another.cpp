//2096. Step-By-Step Directions From a Binary Tree Node to Another
//TC - O(N ) where N is number of nodes in binary tree
//SC - O(N)
class Solution{
public:
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(!root) return NULL;
        if(root->val == startValue || root->val == destValue) return root;
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        if(left && right) return root;
        return left ? left : right;
    }

    bool findNode(TreeNode* root, string& path, int val){
        if(!root) return false;
        if(root->val == val) return true;

        path.push_back('L');
        if(findNode(root->left, path, val)) return true;
        path.pop_back();

        path.push_back('R');
        if(findNode(root->right, path, val))  return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue){
        TreeNode* lca = findLCA(root, startValue, destValue);
		string startUrl = "", destUrl = "";
        findNode(lca, startUrl, startValue);
        findNode(lca, destUrl, destValue);
        for(auto &ch : startUrl) ch = 'U';
        return startUrl + destUrl;
    }
};
