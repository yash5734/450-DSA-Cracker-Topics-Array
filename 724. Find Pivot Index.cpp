class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum =0;
        int totalSum = 0;
        for(auto it:nums){
            totalSum+=it;
        }

        for(int i=0;i<nums.size();i++){
            int rightSum = totalSum-leftSum-nums[i];
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
