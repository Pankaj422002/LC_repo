// 3208_alternatingGp2.cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        int ans=0,n=arr.size();
        int i=0,j=0,curr=-1,prev=-1;
        while(j<n){
            prev=curr;
            curr=arr[j];

            if(j-i+1 < k){
                if(curr==prev)i=j;
                j++;
            }else{
                if(curr==prev)i=j;
                else {
                    ans++;i++;
                }
                j++;
            }
        }

        j=0,prev=arr[n-1];
        while(j<k-1){
            curr=arr[j];
            if(curr==prev){i=j;break;}
            int sz = (n-i)+j+1;
            if(sz == k){
                ans++;
                i++;
            }
            prev=curr;
            j++;
        }

        return ans;
    }
};