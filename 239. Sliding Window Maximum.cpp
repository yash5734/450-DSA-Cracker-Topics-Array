class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){

            // remove if deque have out of boundary element

            if(!dq.empty() && dq.front() == i-k) {
                dq.pop_front();
            }

            // remove if dequeu has non decreasing order

            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // push the ans into array if index is greater then the k;

            if(i >=k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
