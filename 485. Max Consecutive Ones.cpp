class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // if(nums.size()==1){
        //     return nums[0];
        // }
        int count = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxi = max(count,maxi);
            } 
            else count = 0;
        }
        return maxi;
    }
};
