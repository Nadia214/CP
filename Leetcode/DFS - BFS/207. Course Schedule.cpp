//207. Course Schedule
//Tc - O(N + E) wher N  = num of courses , E = number of prequisite
//sc - O(N)
class Solution {
public:
    bool dfs(int i, vector<list<int>>& adj, vector<int>& clr) {
        clr[i] = 1;
        for(int &v : adj[i]) {
            if(clr[v] == 1) return true;
            else if(clr[v] == 0 && dfs(v, adj, clr))
                   return true;
        }
       clr[i] = 2;
       return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> adj(numCourses);
        vector<int>clr(numCourses, 0);

        for(auto &crs : prerequisites)
            adj[crs[1]].push_back(crs[0]);

        for(int i = 0; i < numCourses; i++) {
            if(clr[i] == 0 && dfs(i, adj, clr))
               return false;
        }
        return true;

    }
};
