class Solution {
    private:
    int solve(int ind, int size, string str, vector<int>&dp){
        if(ind==size){
            return 1;
        }

        if(dp[ind]!=-1) return dp[ind];
        int res = 0;
        if(str[ind]!='0'){
            res+=solve(ind+1,size,str,dp);
        }

        if(str[ind]!='0' && ind+1 < size && (str[ind]=='1'||str[ind]=='2' && str[ind+1]<='6'))
            res+=solve(ind+2,size,str,dp);
        
        return dp[ind] = res;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.length() ,-1);
        return solve(0,s.length(),s,dp);
    }
};
