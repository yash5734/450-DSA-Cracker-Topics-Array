class Solution {
    private:
    bool possible(vector<int>& nums, int m, int k, int day){
        int count =0;
        int buke =0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=day){
                count++;
            }else{
                buke += count/k; 
                count =0;
            }
        }
        buke+=count/k;
        return buke>=m;

    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long temp = 1LL * m*k;
        if(temp>n) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        int start = mini;
        int end = maxi;
        int mid = start+(end-start)/2;

        while(start<=end){

            if(possible(nums,m,k,mid))
                end = mid-1;
            else start = mid+1;
            mid = start+(end-start)/2;
        }
        return start;
    }
};
