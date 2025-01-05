// 2381_shiftingLetter2.cpp
/* JAI SHREE RAM */

#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
#define int 			long long int
#define F 				first
#define S 				second
#define pb 				push_back
#define si 				set<int>
#define vi 				vector<int>
#define pii 			pair<int,int>
#define vpi 			vector<pii>
#define vpp 			vector<pair<int,pii>>
#define mii 			map<int,int>
#define umii			unordered_map<int,int>
#define mpi 			map<pii, int>
#define spi 			set<pii>
#define endl 			"\n"
#define sz(x) 			((int) x.size())
#define all(p) 			p.begin(), p.end()
#define double 			long double
#define que_max 		priority_queue<int>
#define que_min			priority_queue<int, vi, greater<int>>

#ifndef ONLINE_JUDGE
#define bug(...) 		__f (#__VA_ARGS__, __VA_ARGS__)
#endif

#define print(a) 		for(auto x: a)cout<<x<<" ";cout<<endl
#define print1(a) 		for(auto x: a)cout<<x.F<<" "<<x.S<<endl
#define print2(a,x,y) 	for(int i=x;i<y;i++)cout<<a[i]<<" ";cout<<endl

inline int power(int a, int b){
	int x=1;
	while(b){
		if(b&1)x=x*a;
		a=a*a;
		b=b>>1;
	}
	return x;
}

#ifndef ONLINE_JUDGE
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout<< name << " : " << arg1<<endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names+1, ',');
	cout.write(names, comma - names) << " : "<<arg1<<" | "; __f(comma+1, args...);
}
#endif

string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> diffArray(
        n, 0);  // Initialize a difference array with all elements set to 0.

    for (auto shift : shifts) {
        if (shift[2] == 1) {        // If direction is forward (1):
            diffArray[shift[0]]++;  // Increment at the start index to
                                    // indicate a forward shift.
            if (shift[1] + 1 < n) {
                diffArray[shift[1] +
                          1]--;  // Decrement at the end+1 index to stop the
                                 // effect of the shift.
            }
        } else {                    // If direction is backward (0):
            diffArray[shift[0]]--;  // Decrement at the start index to
                                    // indicate a backward shift.
            if (shift[1] + 1 < n) {
                diffArray[shift[1] +
                          1]++;  // Increment at the end+1 index to stop the
                                 // effect of the shift.
            }
        }
    }

    string result(n, ' ');
    int numberOfShifts = 0;

    for (int i = 0; i < s.size(); i++) {
        numberOfShifts = (numberOfShifts + diffArray[i]) %
                         26;  // Update cumulative shifts, keeping within
                              // the alphabet range.
        if (numberOfShifts < 0)
            numberOfShifts +=
                26;  // Ensure `numberOfShifts` is non-negative.

        // Calculate the new character by shifting `s[i]`
        result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
    }

    return result;
}

void solve(){
	string str;cin>>str;
	int n;cin>>n;
	vector<vector<int>> shifts(n, vector<int>(3));

	for(int i=0;i<n;i++){
		cin>>shifts[i][0]>>shifts[i][1]>>shifts[i][2];
	}

	cout<<shiftingLetters(str, shifts)<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif


	int t=1;
	cin>>t;
	while(t--)solve();

#ifndef ONLINE_JUDGE
	clock_t z = clock();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
#endif


	return 0;
}