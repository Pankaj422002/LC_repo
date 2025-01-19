// 407_trappingRainWater2.cpp
class Solution {
public:
    #define ppi pair<int,pair<int,int>>
    #define F   first
    #define S   second

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    bool ispossible(int i, int j, int n, int m){
        if(i>=0 and i<n and j>=0 and j<m)return true;
        return false;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(), m=heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        priority_queue<ppi,vector<ppi>,greater<ppi>> min_heap;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    visited[i][j]=true;
                    min_heap.push({heightMap[i][j], {i,j}});
                }
            }
        }

        int ans=0,level=0;
        while(!min_heap.empty()){
            ppi temp = min_heap.top();min_heap.pop();
            int ht = temp.F, i=temp.S.F, j=temp.S.S;
            level=max(level, ht);

            for(int k=0;k<4;k++){
                int x = i+dx[k], y = j+dy[k];
                if(ispossible(x,y,n,m) and !visited[x][y]){
                    if(heightMap[x][y]<level)ans+=(level - heightMap[x][y]);

                    visited[x][y]=true;
                    min_heap.push({heightMap[x][y], {x, y}});
                }
            }

        }

        return ans;
    }
};