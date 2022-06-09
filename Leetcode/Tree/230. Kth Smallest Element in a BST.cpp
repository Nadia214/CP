//230. Kth Smallest Element in a BST
//TC: O(N)
//SC: O(1)
class Solution {
public:
    void runInOrder(TreeNode* root, int &k, int &kthValue) {
        if(!root) return;
        runInOrder(root->left, k, kthValue);
        k--;
        if(k == 0) {
            kthValue = root->val;
        }
        runInOrder(root->right, k, kthValue);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kthValue;
        runInOrder(root, k, kthValue);
        return kthValue;
    }
};
