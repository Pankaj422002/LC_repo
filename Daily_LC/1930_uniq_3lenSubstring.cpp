// 1930_uniq_3lenSubstring.cpp
class Solution {
    class SGTTree{
        vector<pair<long long,long long>> seg;
        public:
        SGTTree(int n){
            seg.resize(4*n);
        }

        int noofsetbits(int mask){
            int cnt=0;
            while(mask){
                if(mask&1)cnt++;
                mask = mask>>1;
            }
            return cnt;
        }

        void build(int idx, int low, int high, string &str){
            //base case: 
            if(low == high){
                int mask = 1<<(str[low]-'a');
                seg[idx]={1,mask};
                return;
            }

            //recursive case: 
            int mid = (low+high)>>1;
            build(2*idx+1,low,mid,str);
            build(2*idx+2,mid+1,high,str);

            int mask1 = seg[2*idx+1].second;
            int mask2 = seg[2*idx+2].second;
            int mask = mask1 | mask2;
            int uq = noofsetbits(mask);

            seg[idx] = {uq,mask};

        }

        pair<int,int> query(int idx, int low, int high, string &str, int l, int r){
            //base case: 
            //no overlap: low high l r or l r low high:
            if(high < l or r < low){
                return {0,0};
            }
            
            //complete overlap: l low high  r :
            if(low>=l and high<=r){
                return seg[idx];
            }

            int mid = (low + high)>>1;
            pair<int,int> left = query(2*idx+1,low,mid,str,l,r);
            pair<int,int> right = query(2*idx+2,mid+1,high,str,l,r);

            int mask1=left.second;
            int mask2=right.second;
            int mask = mask1|mask2;
            int uq = noofsetbits(mask);

            return {uq, mask};

        }

    };

public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        SGTTree S(n);

        S.build(0,0,n-1,s);

        unordered_map<char, vector<int>> mp;
        for(int i=0;s[i]!='\0';i++)mp[s[i]].push_back(i);

        int res=0;
        for(auto it: mp){
            char ch = it.first;
            int first = it.second.front();
            int last = it.second.back();

            if(last == first)continue;

            //find the unique element b/w it: 
            int temp=S.query(0,0,n-1,s,first+1,last-1).first;

            res += temp;

        }

        return res;

    }
};