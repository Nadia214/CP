//124. Binary Tree Maximum Path Sum
//Tc - O(N) where N is the number of nodes
//sc - O(H = log(N)) where H is the height of this binary tree
class Solution {
public:
    int mxPathSum;
    int findMaxChainSum(TreeNode* root) {
        if(root == NULL) return 0;
	    int L = findMaxChainSum(root -> left);
        int R = findMaxChainSum(root -> right);
        mxPathSum = max(mxPathSum, root -> val + L + R);
        return max(0, max(L, R) + root->val);

    }
    int maxPathSum(TreeNode* root) {
        mxPathSum = INT_MIN/2;
        findMaxChainSum(root);
        return mxPathSum;
    }
};
