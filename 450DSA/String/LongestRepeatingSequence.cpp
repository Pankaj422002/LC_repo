//Longest Repeating Subsequence
//Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
//
//The two identified subsequences A and B can use the same ith character from string s if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the original string for A and B.
//
//Examples :
//
//Input: s = "axxzxy"
//Output: 2
//Explanation: The given array with indexes looks like
//a x x z x y 
//0 1 2 3 4 5
//The longest subsequence is "xx". It appears twice as explained below.
//subsequence A
//x x
//0 1  <-- index of subsequence A
//------
//1 2  <-- index of s
//subsequence B
//x x
//0 1  <-- index of subsequence B
//------
//2 4  <-- index of s
//We are able to use character 'x' (at index 2 in s) in both subsequences as it appears on index 1 in subsequence A and index 0 in subsequence B.
//Input: s = "axxxy"
//Output: 2
//Explanation: The given array with indexes looks like
//a x x x y 
//0 1 2 3 4
//The longest subsequence is "xx". It appears twice as explained below.
//subsequence A
//x x
//0 1  <-- index of subsequence A
//------
//1 2  <-- index of s
//subsequence B
//x x
//0 1  <-- index of subsequence B
//------
//2 3  <-- index of s
//We are able to use character 'x' (at index 2 in s) in both subsequencesas it appears on index 1 in subsequence A and index 0 in subsequence B.
//Constraints:
//1 <= s.size() <= 103

#include<bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j, vector<vector<int>> &dp){
    int n=str1.length(), m=str2.length();

    if(i==n || j==m)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];

    if(str1[i] == str2[j] and i!=j){
        return dp[i][j]=max({1+solve(str1,str2,i+1,j+1,dp), solve(str1,str2,i+1,j,dp), solve(str1,str2,i,j+1,dp)});
    }
    return dp[i][j]=max(solve(str1,str2,i+1,j,dp), solve(str1,str2,i,j+1,dp));

}

int solveDP(string &str){
    int n=str.length();
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i-1] == str[j-1] and i!=j){
                dp[i][j] = max({1+dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

int LongestRepeatingSequence(string str){
    //int n=str.length();
    //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //return solve(str,str,0,0,dp);
    return solveDP(str);
}

int main(){
    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    string str;cin>>str;
    cout<<LongestRepeatingSequence(str)<<endl;

    return 0;
}





















