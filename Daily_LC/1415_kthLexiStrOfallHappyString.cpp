class Solution {
public:
    #define pbs pair<bool,string>
    #define F   first
    #define S   second
    pbs getans(int n, int &k, int lst,string curr){
        if(n==0){
            k--;
            if(k==0)
                return {true,curr};
            else 
                return {false, curr};
        }

        for(int i=0;i<3;i++){
            if(lst == -1 || i!=lst){
                pbs temp = getans(n-1,k,i,curr+(char)('a'+i));
                if(temp.F)return temp;
            }
        }

        return {false,curr};
    }

    string getHappyString(int n, int k) {
        pbs ans=getans(n,k,-1,"");
        if(ans.F)return ans.S;
        return "";
    }
};
