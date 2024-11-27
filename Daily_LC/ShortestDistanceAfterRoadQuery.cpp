// ShortestDistanceAfterRoadQuery.cpp
class Graph{
public: 
    vector<vector<int>> adj;
    int v;
    Graph(int v){
        this->v = v;
        for(int i=0;i<v;i++){
            vector<int> temp;
            adj.push_back(temp);
        }
    }

    void addEdge(int x, int y){
        adj[x].push_back(y);
    }

    int SSIP(int src , int dest){

        queue<int> q;
        q.push(src);
        vector<int> visited(v, false);
        visited[src]=true;

        int level=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int temp = q.front();q.pop();

                if(temp == dest)return level;

                for(auto nbr: adj[temp]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }

            }
            level++;
        }

        // return level-1;
        return -1;
    }

};

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    Graph G(n);
    for(int i=0;i<n-1;i++)
        G.addEdge(i, i+1);
    
    vector<int> ans;
    for(auto it: queries){
        G.addEdge(it[0],it[1]);
        ans.push_back(G.SSIP(0,n-1));
    }

    return ans;
}