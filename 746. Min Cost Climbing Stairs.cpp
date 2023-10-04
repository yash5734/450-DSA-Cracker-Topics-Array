class Solution {
public:
    int solve(int ind, vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];

        int first = solve(ind+1,nums,dp)+nums[ind];
        int second = INT_MAX;
        if(ind<nums.size()-1){
            second = solve(ind+2,nums,dp) + nums[ind];
        }

        return dp[ind] = min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};
