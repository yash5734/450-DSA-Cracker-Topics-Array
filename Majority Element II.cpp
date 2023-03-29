class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int key = n/3;
        int c =0;
        vector<int> res;
       
        set<int>res2;
        if(n ==1){
            return nums;
        }
        if(n==2){
            if(nums[0]==nums[1]){
                res.push_back(nums[0]);
                return res;
            }
            
            return nums;
        }
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                c++;
                if(c>=key){
                    res2.insert(nums[i]);
                    c =0;
                }
            }else c =0;
        }
         vector<int> res1(res2.begin(),res2.end());
        return res1;

    }
};
