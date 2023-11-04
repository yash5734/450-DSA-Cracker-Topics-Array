class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        // use map to check weather the number is present or not
        unordered_map<int,int>mp;
        int maxi =0;

        for(auto it:target){
            maxi = max(maxi,it);
            mp[it]++;
        }
        vector<string>ans;

        
        // maxi is use bcz we want to itereate only the range of target element,
        // so we start from 1 to max of target element
        for(int i=1;i<=maxi;i++){
            if(mp.find(i) != mp.end()){
                ans.push_back("Push");
            }
            else{ // if not present in target array then first we push and then pop
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
