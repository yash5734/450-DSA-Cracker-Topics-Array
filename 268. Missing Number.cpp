class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N =nums.size();
        int hash[nums.size() + 1];
        for(int i=0;i<=N;i++){
            hash[i] = 0;
        }
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<=N;i++){
            if(hash[i]==0) return i;
        }
        return -1;
    }
};
