//236. Lowest Common Ancestor of a Binary Tree
//TC - O(N),N is number of nodes in a tree
//SC - O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
	    if(root -> val == p->val || root->val == q->val) return root;
	    auto L = lowestCommonAncestor(root->left, p, q);
	    auto R = lowestCommonAncestor(root->right, p, q);
        if(L && R) return root;
        return L? L: R;
    }
};
