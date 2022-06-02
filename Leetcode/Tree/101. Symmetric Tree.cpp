//101. Symmetric Tree
//TC -O(N = number of nodes)
//SC - O(1)
class Solution {
public:
    bool check(TreeNode* L, TreeNode* R) {
        if(!L && !R) return true;
        if(!L || !R || L->val != R->val) return false;

        return (check(L->left, R->right) && check(L->right, R->left));
    }
    bool isSymmetric(TreeNode* root) {
        return check(root -> left, root-> right);
    }
};
