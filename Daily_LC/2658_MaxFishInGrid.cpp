// 2658_MaxFishInGrid.cpp
class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    bool ispossible(int i, int j, int n, int m){
        if(i>=0 and i<n and j>=0 and j<m)return true;
        return false;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, int &temp, vector<vector<bool>> &visited){
        if(visited[i][j] || grid[i][j]==0)return;

        visited[i][j]=true;
        temp+=grid[i][j];

        int n=grid.size(),m=grid[0].size();
        for(int k=0;k<4;k++){
            if(ispossible(i+dx[k], j+dy[k], n, m))
                dfs(i+dx[k], j+dy[k], grid, temp, visited);
        }

    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and grid[i][j]!=0){
                    int temp=0;
                    dfs(i,j,grid,temp, visited);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};