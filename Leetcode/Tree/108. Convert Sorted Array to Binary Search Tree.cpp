//108. Convert Sorted Array to Binary Search Tree
//TC: O(N), where N is number of nodes
//SC: O(h), where h is the height of the BST
class Solution {
public:
    TreeNode* constructBST(vector<int>& nums, int L, int R) {
		if(L > R) return NULL;
	    int M = L +(R - L)/2;
		TreeNode* curr = new TreeNode(nums[M]);
		curr ->left = constructBST(nums, L, M-1);
		curr ->right = constructBST(nums, M + 1, R);
		return curr;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }
};
