//TC - O(N) ; N = number of nodes
//SC - O(max depth of the tree)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return NULL;
        auto L = 1 + maxDepth(root->left);
        auto R = 1 + maxDepth(root->right);
        return max(L, R);
    }
};
