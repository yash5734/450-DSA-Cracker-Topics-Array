class Solution {
public:

    void f(vector<int>& arr,vector<int>& ds,vector<vector<int>> &ans,int* freq){

        if(ds.size()==arr.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<arr.size();i++){
            if(freq[i]==0){
                freq[i] = 1;
                ds.push_back(arr[i]);
                f(arr,ds,ans,freq);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> ds;
       int n = nums.size();
      int freq[nums.size()]; 
      for(int i =0 ;i<nums.size();i++){
          freq[i] = 0;
      }

       f(nums,ds,ans,freq);
       return ans; 
    }
};
