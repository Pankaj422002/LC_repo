class Solution {
public:
    #define pipii pair<int,pair<int,int>>

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    bool ispossible(int i, int j, int m, int n){
        if(i>=0 and i<m and j>=0 and j<n)return true; 
        return false;
    }

    int bfs(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<pipii,vector<pipii>, greater<pipii>> min_heap;   //{cost, i, j}
        min_heap.push({0,{0,0}});
        visited[0][0]=1;

        int ans = INT_MAX;
        while(!min_heap.empty()){
            pipii temp = min_heap.top();
            min_heap.pop();

            int curr_cost = temp.first;
            int x = temp.second.first, y=temp.second.second;

            if(x == m-1 and y==n-1)ans=min(ans, curr_cost);

            for(int k=0;k<4;k++){

                if(ispossible(x+dx[k], y+dy[k], m, n) and !visited[x+dx[k]][y+dy[k]]){
                    visited[x+dx[k]][y+dy[k]]=1;
                    min_heap.push({curr_cost+grid[x+dx[k]][y+dy[k]],{x+dx[k], y+dy[k]}});
                }

            }

        }
        return ans;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        return bfs(grid);
    }

};
