class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int rem = target-nums[i];
            if(mpp.count(rem)){
                return {i,mpp[rem]};
            }
            mpp[nums[i]] = i;
        }
        return {0,0};
        
    }
};
