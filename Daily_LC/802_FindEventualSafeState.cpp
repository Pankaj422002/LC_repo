class Solution {
public:
    bool dfs(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dp){

        if(dp[src]!=-1)return dp[src];

        visited[src]=true;
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                bool temp = dfs(nbr, adj, visited, dp);
                if(temp==false)return dp[src]=false;
            }else{
                return dp[src]=false;
            }
        }
        visited[src]=false;
        return dp[src]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> ans;
        vector<bool> visited(n, false);

        vector<int> dp(n, -1);
        for(int i=0;i<n;i++){
            if(dfs(i, graph, visited, dp))ans.push_back(i);
        }
        return ans;
    }
};
