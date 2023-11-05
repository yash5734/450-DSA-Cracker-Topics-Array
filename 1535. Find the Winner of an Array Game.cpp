class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int maxi = arr[0];

        for(int i=1;i<arr.size();i++){
            maxi = max(maxi,arr[i]);
            mp[maxi]++;
            if(mp[maxi] >= k) return maxi;
        }
        return maxi;
    }
};
