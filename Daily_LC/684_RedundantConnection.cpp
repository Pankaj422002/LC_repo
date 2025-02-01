// 684_RedundantConnection.cpp
class Solution {
public:
    class DSU{
        int n;
        vector<int> rank,parent;
        public: 
        DSU(int n){
            this->n = n;
            rank.resize(n, 1);
            for(int i=0;i<n;i++)parent.push_back(i);
        }
        int find(int s){
            if(parent[s]==s)return s;
            return parent[s]=find(parent[s]);
        }
        void UNION(int a, int b){
            int s1=find(a);
            int s2=find(b);
            if(s1 != s2){
                if(rank[s1]>=rank[s2]){
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }else{
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
            }
        }

        bool isconnected(int x, int y){
            if(find(x) != find(y))return false;
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        DSU S(1001);
        for(auto it: edges){
            if(S.isconnected(it[0],it[1]))ans=it;
            S.UNION(it[0],it[1]);
        }
        return ans;
    }
};