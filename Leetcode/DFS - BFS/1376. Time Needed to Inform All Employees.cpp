//1376. Time Needed to Inform All Employees
//Tc - O(2^n) - n array tree
//sc - O(n)
class Solution {
public:
    vector<vector<int>> adjacentNodes;
    int findMinTime(int u, vector<int>&informTime)
    {
        int maxSubordinatetime = 0;
	    for(auto v : adjacentNodes[u])
        {
            maxSubordinatetime = max(maxSubordinatetime, findMinTime(v, informTime));
        }
      return maxSubordinatetime + informTime[u];
    }
    int numOfMinutes(int n, int headID, vector<int>& parent, vector<int>& informTime) {
        adjacentNodes.clear();
        adjacentNodes.resize(n + 1);
        for(int i = 0;  i  < parent.size(); i++)
        {
            if(parent[i] != -1)
            {
                adjacentNodes[parent[i]].push_back(i);
            }
        }
        return findMinTime(headID, informTime);
    }
};
