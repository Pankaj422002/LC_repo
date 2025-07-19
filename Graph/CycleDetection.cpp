// CycleDetection.cpp
#include<bits/stdc++.h>

using namespace std;

class GraphUndirected{
public: 
	vector<vector<int>> adj;
	int n;

	Graph(int v){
		this->n = v;
		for(int i=0;i<v;i++){
			vector<int> temp;
			adj.push_back(temp);
		}
	}

	void addEdge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	bool dfs(int src, vector<bool> &visited, vector<int> &parent){

		visited[src]=true;

		for(auto nbr: adj[src]){
			if(!visited[nbr]){

				parent[nbr]=src;
				bool isCycleFound = dfs(nbr, visited, parent);
				
				if(isCycleFound)return true;

			}else if(visited[nbr] and parent[src]!=nbr){
				return true;
			}
		}

		return false;

	}

	bool isCycleDFS(){

		int src = 0;

		vector<bool> visited(n, false);
		vector<int> parent(n, -1);

		for(int i=0;i<n;i++){
			if(!visited[i]){
				bool isCycleFound = dfs(i,visited, parent);
				if(isCycleFound)return true;
			}
		}
		return false;

	}

	bool isCycleBFS(){
		int src=0;
		vector<bool> visited(n, false);
		parent<int> parent(n, -1);

		q.push(src);
		visited[src]=true;
		parent[src]=src;

		while(!q.empty()){
			int sz = q.size();
			for(int i=0;i<n;i++){

				int temp = q.front();q.pop();
				for(auto nbr: adj[temp]){
					if(!visited[nbr]){
						q.push(nbr);
						visited[nbr]=true;
					}else if(visite[nbr] and parent[src]!=nbr){
						return true;
					}
				}

			}
		}
		return false;

	}
};

class GraphDirected{
public:
	vector<vector<int>> adj;
	int n;

	GraphDirected(int v){
		this->n=v;
		for(int i=0;i<v;i++){
			vector<int> temp;
			adj.push_back(temp);
		}
	}

	void addEdge(int x, int y){
		adj[x].push_back(y);
	}

	bool dfs(int src, vector<bool> &visited, vector<int> &parent, vector<int> &stack){
		visited[src]=true;
		stack[src]=true;

		for(auto nbr: adj[src]){
			if(!visited[nbr]){
				parent[nbr]=src;
				bool isCycleFound = dfs(nbr,visited,parent,stack);
				if(isCycleFound)return true;
			}else if(visited[nbr] and stack[nbr]=true){
				return true;
			}
		}

		stack[src]=false;
		return false;
	}

	bool isCycleDFS(){
		int src=0;
		vector<bool> visited(n, false);
		vector<int> parent(n, -1);
		vector<int> stack(n, false);

		for(int i=0;i<n;i++){
			if(!visited[i]){
				bool isCycleFound = dfs(src, visited, parent, stack);
				if(isCycleFound)return true;
			}
		}

		return false;
	}

	bool isCycleBFS(){

		

	}

};

int main(){



#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	return 0;
}