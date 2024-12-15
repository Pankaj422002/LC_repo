class Solution {
public:
    #define pdi pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();

        priority_queue<pdi> max_heap;
        for(int i=0;i<classes.size();i++){
            double nu=classes[i][0], dr=classes[i][1];
            double nu1=nu+1, dr1 = dr+1;
            double diff = (double)nu1/dr1 - (double)nu/dr;
            max_heap.push({diff, i});
        }

        while(extraStudents--){
            pdi temp = max_heap.top();max_heap.pop();
            int c_idx=temp.second;

            classes[c_idx][0]++;
            classes[c_idx][1]++;

            double nu=classes[c_idx][0], dr=classes[c_idx][1];
            double nu1=nu+1, dr1 = dr+1;


            double diff = (double)nu1/dr1 - (double)nu/dr;
            max_heap.push({diff, c_idx});
        }

        double ans=0.0;
        for(int i=0;i<n;i++){
            ans += (double)classes[i][0]/classes[i][1];
        }
        return ans/n;

    }
};
