// 1462_courseSchedule4.cpp
class Solution {
public:
    bool bfs(int src, int dest, vector<vector<int>> &adj){
        queue<int> q;
        q.push(src);

        int sz=adj.size();
        vector<bool> visited(sz,false);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int temp=q.front();q.pop();

                if(temp == dest)return true;

                visited[temp]=true;
                for(auto nbr: adj[temp]){
                    if(!visited[nbr])q.push(nbr);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            vector<int> temp;
            adj.push_back(temp);
        }

        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> ans;
        for(auto it: queries){
            if(bfs(it[1], it[0], adj))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};