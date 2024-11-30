// ValidAarrangementOfPairs_EULERS_PATH.cpp
class Solution {
    map<int,vector<int>> adj;
    map<int,int> inDegree,outDegree;

    int getStartNode(){
        int start_node;
        for(auto& [node,degree]: outDegree){
            if(degree - inDegree[node] == 1)    return node;//If only Euler path exists but not Euler Circuit
            if(degree > 0)  start_node = node;
        }
        return start_node;//Euler circuit & Euler path both exists
    }
    void getEulerianPath(int curr,vector<int>& eulerian_path){
        while(outDegree[curr]){
            outDegree[curr]--;
            int next_node = adj[curr][outDegree[curr]];
            getEulerianPath(next_node,eulerian_path);
        }
        eulerian_path.push_back(curr);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto& pair: pairs){
            int from = pair[0];
            int to = pair[1];

            adj[from].push_back(to);
            outDegree[from]++;
            inDegree[to]++;
        }

        int start_node = getStartNode();//Eulerian path is guaranteed in this problem

        vector<int> eulerian_path;
        getEulerianPath(start_node,eulerian_path);
        
        vector<vector<int>> res;
        for(int i=eulerian_path.size()-1; i>0; --i){
            vector<int> path;
            path.push_back(eulerian_path[i]);
            path.push_back(eulerian_path[i-1]);
            res.push_back(path);
        }
        return res;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
