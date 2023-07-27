class Solution {
private:
void f(int ind,int n, vector<int>& nums, vector<int>ds, set<vector<int>>&st){
    if(ind >= n){
        sort(ds.begin(),ds.end());
        st.insert(ds);
        return;
    }

    ds.push_back(nums[ind]);
    f(ind+1,n,nums,ds,st);
    ds.pop_back();
    f(ind+1,n,nums,ds,st);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>ds;
        set<vector<int>>st;
        f(0,n,nums,ds,st);

        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
