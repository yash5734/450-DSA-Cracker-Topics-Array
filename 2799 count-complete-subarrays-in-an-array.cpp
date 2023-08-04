class Solution {
    private:
    int distinct(vector<int>nums){
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        return st.size();
    }

public:
    int countCompleteSubarrays(vector<int>& nums) {
        int start =0;
        int n = nums.size();
        int end =n-1;
        int k=distinct(nums);
        int cnt=0;

        while(start<n){

            set<int>st;
            for(int i=start;i<=end;i++){
                st.insert(nums[i]);

                if(st.size()==k) cnt++;
            }
            start++;
        }
        return cnt;
    }
};
