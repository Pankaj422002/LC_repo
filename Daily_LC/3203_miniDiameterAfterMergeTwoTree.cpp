class Solution {
public:

    pair<int,int> dfs(int src, unordered_map<int,vector<int>> &adj, vector<int> &visited){

        int ans_diam=0,ans_ht=0;

        priority_queue<int> max_heap;
        
        visited[src]=true;
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                pair<int,int> temp = dfs(nbr, adj, visited);
                //calculate diameter: 
                ans_diam =  max(ans_diam, temp.first);

                max_heap.push(temp.second+1);

                //calculate ht : 
                ans_ht = max(ans_ht, temp.second+1);
            }
        }

        if(max_heap.empty()){
            return {ans_diam, ans_ht};
        }

        int h1 = max_heap.top();max_heap.pop();

        if(max_heap.empty()){
            ans_diam = max(ans_diam, h1);
            return {ans_diam, ans_ht};
        }
        int h2 = max_heap.top();max_heap.pop();
        ans_diam = max(ans_diam, h1+h2);

        return {ans_diam, ans_ht};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        unordered_map<int,vector<int>> adj1, adj2;

        for(auto it: edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        vector<int> visited1(adj1.size(), 0);

        for(auto it: edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<int> visited2(adj2.size(), 0);


        pair<int,int> d1 = {0,0};
        if(adj1.size()!=0)
            d1 = dfs(0, adj1, visited1);

        pair<int,int> d2 = {0,0};
        if(adj2.size()!=0)
            d2 = dfs(0, adj2, visited2);

        int diam_1 = d1.first, diam_2 = d2.first;
        
        int ans=0;
        ans += ((diam_1%2==0)? diam_1/2: (diam_1+1)/2);
        ans += ((diam_2%2==0)? diam_2/2: (diam_2+1)/2);
        return max({ans+1, diam_1, diam_2});
    }
};
