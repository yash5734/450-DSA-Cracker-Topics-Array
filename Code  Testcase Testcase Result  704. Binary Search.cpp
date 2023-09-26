class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        int mid = left + (right-left)/2;

        while(left<=right){
            if(arr[mid]==target) return mid;
            else if(arr[mid]>target) right = mid-1;
            else left = mid+1;

            mid = left + (right-left)/2;
        }
        return -1;
    }
};
