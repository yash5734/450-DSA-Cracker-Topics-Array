class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        int k=0;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);

            }
            else{
                neg.push_back(nums[i]);
            }
        }
        // int i=0,k=0,j=0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0){
            ans.push_back(pos[k++]);
            }
            else{
            ans.push_back(neg[j++]);
            }
        }
        return ans;
    }
};
