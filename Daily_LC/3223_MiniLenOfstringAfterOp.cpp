// 3223_MiniLenOfstringAfterOp.cpp
#include<bits/stdc++.h>

using namespace std;

int minimumLength(string s) {
    unordered_map<char,int> mp;
    for(auto it: s)mp[it]++;
    int ans =0;
    for(auto it: mp){
        if(it.second>2)ans += (it.second%2 == 0 ? 2 : 1);
        else ans+=it.second;
    }
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	string str;cin>>str;
	cout<<minimumLength(str)<<endl;

	return 0;
}