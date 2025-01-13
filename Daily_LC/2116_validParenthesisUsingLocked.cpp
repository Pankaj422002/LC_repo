// 2116_validParenthesisUsingLocked.cpp
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int wc1=0,open=0,close=0,n=s.length();

        if(n%2 != 0)return false;

        for(int i=0;i<n;i++){
            if(locked[i]=='0')wc1++;
            else if(locked[i]=='1' and s[i]=='(')open++;
            else if(locked[i]=='1' and s[i]==')')close++;
            
            if(open+wc1 < close)return false;
        }

        open=0,close=0,wc1=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0')wc1++;
            else if(locked[i]=='1' and s[i]=='(')open++;
            else if(locked[i]=='1' and s[i]==')')close++;

            if(close+wc1 < open)return false;
        }

        return true;
    }
};