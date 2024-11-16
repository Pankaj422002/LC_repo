#include <bits/stdc++.h>
using namespace std;

int solve(){
    int l,r;cin>>l>>r;
    int l_expected = (r%2 == 0)?(r/2):((r/2)+1);
    
    int ans = (l_expected<=l ? r : -1) ;
    if(ans%l == ans%r)return -1;
    
    return ans;
}

int main() {
	// your code goes here
    int t;cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
