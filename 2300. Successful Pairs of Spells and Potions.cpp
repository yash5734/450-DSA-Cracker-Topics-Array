class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        int n = potions.size();

        for(int i=0;i<spells.size();i++){
            int count=0;
            int left = 0;
            int right = potions.size()-1;
            int mid = left + (right-left)/2;
            while(left<=right){
                long long sum = 1LL*spells[i] * potions[mid];

                if(sum>=success){
                    count = potions.size()-mid;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
                mid = left + (right-left)/2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
