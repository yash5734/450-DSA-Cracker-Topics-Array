class Solution {
private:
    int robHelper(vector<int>& nums, int ind,vector<int>&dp) {
        if (ind < 0) {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + robHelper(nums, ind - 2,dp);
        int notTake = robHelper(nums, ind - 1,dp);
        dp[ind] = max(take, notTake);
        return dp[ind];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return robHelper(nums, n - 1,dp);
    }
};
