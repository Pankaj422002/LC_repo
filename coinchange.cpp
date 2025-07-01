int coinChange(vector<int>& coins, int amt) {
    int n=coins.size();

    vector<vector<int>> dp(n+1, vector<int> (amt+1, INT_MAX-1));
    
    dp[0][0]=0;
    for(int j=1;j<=amt;j++)dp[0][j]=INT_MAX-1;
    

    for(int i=0;i<=n;i++)dp[i][0]=0;

    for(int j=1;j<=amt;j++){
        if(j%coins[0] == 0)dp[1][j]=j/coins[0];
        else dp[1][j]=INT_MAX-1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=amt;j++){
            
            if(j>=coins[i-1]){
                dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        
        }
    }
    
    return dp[n][amt]==INT_MAX-1?-1:dp[n][amt];
}

