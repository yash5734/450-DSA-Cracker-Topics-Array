class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>st;

        for(auto it:arr){
            mp[it]++;
        }

        // sort(mp.begin(),mp.end(),cmp);

        for(auto it: mp){
            if(st.count(it.second)>=1) return false;
            st.insert(it.second);
        }
        return true;
    }
};
