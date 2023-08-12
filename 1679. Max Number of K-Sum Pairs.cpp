class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt =0;
        int left =0;
        int right = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(left<right){
            if(nums[left] + nums[right] == k){
                cnt++;
                left++;
                right--;
            }else if(nums[left] + nums[right] < k){
                left++;
            }else right--;
        }
        return cnt;
    }
};
