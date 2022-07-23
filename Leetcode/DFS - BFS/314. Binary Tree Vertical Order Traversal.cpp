//314. Binary Tree Vertical Order Traversal
//Tc - O(n*nlogn)
//Sc - O(n)
class Solution {
public:
    map<int, vector<pair<int, pair<int, int>>>> nodes;
    int rank;
    void dfs(TreeNode* u, int ort = 0, int level = 0) {
        if(u == NULL) return;
        nodes[ort].push_back({level, {rank++, u-> val}});
        dfs(u ->left, ort - 1, level + 1);
        dfs(u-> right, ort + 1, level + 1);
        }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        nodes.clear();
        rank = 0;
        dfs(root);
        vector<vector<int>>vertOrder;
        for(auto &it: nodes) {
            auto nodeList = it.second;
            sort(nodeList.begin(), nodeList.end());
            vector<int>levelNodes;
            for(auto node : nodeList) {
                levelNodes.push_back(node.second.second);
            }
            vertOrder.push_back(levelNodes);

        }
        return vertOrder;
    }
};
