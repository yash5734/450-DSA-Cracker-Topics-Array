class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(auto it:nums1){
            mp1[it]++;
        }

        for(auto it:nums2){
            mp2[it]++;
        }

        vector<vector<int>>ans;
        vector<int>temp;
        for(auto it:mp1){
            
            if(mp2.find(it.first)==mp2.end()){
                temp.push_back(it.first);
            }
        }
        ans.push_back(temp);
        vector<int>temp2;
        for(auto it:mp2){
            if(mp1.find(it.first)==mp1.end()){
                temp2.push_back(it.first);
            }
        }
        ans.push_back(temp2);

        return ans;

    }
};
