class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;
        for(auto it: nums){
            if(it<=a) a = it;
            else if(it<=b) b= it;
            else return true;

        }
        return false;
    }
};
