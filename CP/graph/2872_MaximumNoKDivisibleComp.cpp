// 2872_MaximumNoKDivisibleComp.cpp
class Solution {
public:

    long long dfs(int src, vector<vector<int>> &adj, vector<int> &values, int k, vector<bool> &visited, int &ans){

        visited[src]=true;
        long long temp=values[src];
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                long long curr = dfs(nbr,adj,values,k,visited,ans);
                if(curr%k == 0)ans++;
                else temp+=curr;
            }
        }
        return temp;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            vector<int> temp;
            adj.push_back(temp);
        }

        for(auto it: edges){
            int x=it[0],y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n, false);

        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, adj, values, k, visited, ans);
            }
        }

        return ans+1;

    }
};