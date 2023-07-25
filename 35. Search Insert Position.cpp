class Solution {
    private:
    int binarySearch(int s, int e, vector<int>&arr,int target){

        if(s>=e){
            return s;
        }

        int mid = (s+e)/2;
        if(arr[mid] == target) return mid;

        else if(arr[mid]>target){
            return binarySearch(s,mid,arr,target);
        }
        else{
            return binarySearch(mid+1,e,arr,target);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]) return nums.size();
        return binarySearch(0,nums.size()-1,nums,target);
    }
};
