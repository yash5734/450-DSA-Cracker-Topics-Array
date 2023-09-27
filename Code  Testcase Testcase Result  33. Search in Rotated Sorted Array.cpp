class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start+(end-start)/2;
        while(start<end){
            if(nums[mid]>=nums[0]){
                start = mid+1;
            }else{
                end = mid;
            }
            mid = start+(end-start)/2;
        }
        if(nums[start]>nums[0]) return nums[0];
        return nums[start];
    }
};
