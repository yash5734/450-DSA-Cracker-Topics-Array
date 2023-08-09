class Solution {
public:
    static bool str_greater(string l, string r){
        return l + r > r + l;
    }

    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> new_nums(nums.size());
        for(int i = 0; i < new_nums.size(); i++){
            new_nums[i] = to_string(nums[i]);
        }
        sort(new_nums.begin(), new_nums.end(), str_greater);
        for(auto num: new_nums){
            ans += num;
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }

};
