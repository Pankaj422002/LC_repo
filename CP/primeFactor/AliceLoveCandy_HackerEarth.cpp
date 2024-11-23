#include <bits/stdc++.h>
using namespace std;

#define ll long long int


int main() {

	ll n;cin>>n;
	int ans=0;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i == 0){
			int a=i,b=n/i;

			if((a%2 == 0 and b%2 == 0)||(a%2 != 0 and b%2 != 0)){
				ans+=1;
			}

		}
	}
	cout<<ans<<endl;
	return 0;
}