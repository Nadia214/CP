//98. Validate Binary Search Tree
//TC: O(N) , where N is number of nodes in a tree
//SC: O(n)
class Solution
{
public:
    bool validateBST(TreeNode* root, long long L_min, long long R_max ){
        if(!root)  return true;
        long long v = root->val;
        if(v > R_max || v < L_min) return false;
        return validateBST(root->left, L_min, v - 1) && validateBST(root->right, v + 1, R_max);
    }
    bool isValidBST(TreeNode* root){
        return validateBST(root,LLONG_MIN, LLONG_MAX);
    }
};
