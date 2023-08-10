class Solution {
    bool binarySearch(vector<int>nums, int start, int end, int target){

        if(start>end) return false;

        int mid = (start+end)/2;

        if (nums[mid] > target) {
            return binarySearch(nums, start, mid - 1, target);
        } else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, end, target);
        } else {
            return true; // Target found
        }
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int i1= 0;
        int i2 =0;
        int j1 = n-1;
        int j2 = n-1;

        if(nums.size() ==1) return nums[0] == target;

        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                j1 = i;
                break;    
            }
        }
        if(j1==n-1)return binarySearch(nums,i1,j1,target);
        i2 = j1+1;

        if(nums[i1]<=target && nums[j1]>=target) return binarySearch(nums,i1,j1,target);
        else if(nums[i2]<=target && nums[j2]>=target) return binarySearch(nums,i2,j2,target);
        return false;
    }
};
