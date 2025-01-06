// 1769_miniOperTOmoveAllBalls.cpp
#include<bits/stdc++.h>

using namespace std;

vector<int> minOperations(string boxes) {
    vector<int> pos,ans;
    for(int i=0;i<boxes.size();i++)if(boxes[i]=='1')pos.push_back(i);
    for(int i=0;i<boxes.size();i++){
        int temp=0;
        for(auto it : pos)temp+=abs(i-it);
        ans.push_back(temp);
    }
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	string str;cin>>str;
	vector<int> ans = minOperations(str);
	for(auto it: ans)cout<<it<<" ";
	cout<<endl;
	return 0;
}