class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mp[mat[i][j]]={i,j};


        vector<int> col(m,0);
        vector<int> row(n,0);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<arr.size();i++){
            int ele = arr[i];
            int x=mp[ele].first, y=mp[ele].second;

            if(visited[x][y] == 0){
                visited[x][y]=1;
                col[y]+=1;
                row[x]+=1;
            }
            if(row[x]==m || col[y]==n)return i;
        }
        return -1;
    }
};
