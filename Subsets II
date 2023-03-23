class Solution {
public:
    void f(int ind, int n, vector<int>& arr, vector<int> ds,set<vector<int>> &ans){
        if(ind >= n){
            sort(ds.begin(), ds.end());
            ans.insert(ds);
            return;
        }

        ds.push_back(arr[ind]);
        f(ind+1,n,arr,ds,ans);
        ds.pop_back();
        f(ind+1,n,arr,ds,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        set<vector<int>>ans;
        vector<vector<int>>ans2;
        f(0,n,nums,ds,ans);
        for(auto& it : ans){
            ans2.push_back(it);
        }
        return ans2;
    }
};
