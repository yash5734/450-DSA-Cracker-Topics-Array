class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n);
        stack<int>s;
        for(int i = 2*n-1;i>=0;i--){
            while(!s.empty() && nums[i%n]>=s.top()){
                s.pop();
            }
            arr[i%n] = s.empty()?-1:s.top();
            s.push(nums[i%n]);
        }
        return arr;
    }
};
