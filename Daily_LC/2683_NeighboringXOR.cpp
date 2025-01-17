class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(auto it: derived)if(it==1)x++;
        return x%2==0;
    }
};
