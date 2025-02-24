// 2467_MostProfitablePathinTree.cpp
class Solution {
public:
    #define vi  vector<int>
    #define vb  vector<bool>
    void dfs(vector<vi> &adj, vi &parent, vi &dfroot, int src, vb &visited, int lvl){

        visited[src]=true;
        dfroot[src]=lvl;
        for(auto nbr: adj[src]){
            if(!visited[nbr] and parent[src]!=nbr){
                parent[nbr]=src;
                dfs(adj,parent,dfroot,nbr,visited,lvl+1);
            }
        }

    }

    void populate_dfbob(vi &parent, int bob, vi &dfbob, int root){
        dfbob[bob]=0;
        while(bob!=root){
            dfbob[parent[bob]]=dfbob[bob]+1;
            bob=parent[bob];
        }
    }

    int dfs_ans(vector<vi> &adj, vi &amount, vi &dfroot, vi &dfbob, vb &visited, int src){

        visited[src]=true;

        int curr_ans=0, maxi=INT_MIN;
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                maxi = max(maxi, dfs_ans(adj,amount,dfroot,dfbob,visited,nbr));
            }
        }

        if(dfbob[src]==-1)curr_ans=amount[src];
        else if(dfbob[src]!=-1){
            if(dfroot[src]<dfbob[src])curr_ans=amount[src];
            else if(dfroot[src]>dfbob[src])curr_ans=0;
            else{
                int x = abs(amount[src])/2;
                if(amount[src]<0)curr_ans-=x;
                else curr_ans+=x;
            }
        }


        return curr_ans + (maxi==INT_MIN?0:maxi);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vi> adj(n);
        for(int i=0;i<n-1;i++){
            int x=edges[i][0],y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vb visited(n,false);
        vi parent(n,-1);
        vi dfroot(n,-1);
        dfs(adj,parent,dfroot,0,visited,0);

        vi dfbob(n,-1);
        populate_dfbob(parent,bob,dfbob,0);


        vb isvisited(n,false);
        return dfs_ans(adj,amount,dfroot,dfbob,isvisited,0);

    }
};