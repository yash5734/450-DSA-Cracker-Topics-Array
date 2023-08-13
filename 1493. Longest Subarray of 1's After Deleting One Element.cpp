class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int n = nums.size();
        int left = 0; // Left pointer of the sliding window
        int maxConsecutiveOnes = 0; // Maximum consecutive ones
        int k =1;
        
        for (int right = 0; right < n; ++right) { // Right pointer of the sliding window
            if (nums[right] == 0) {
                k--; // Consume one available flip
            }
            
            if (k < 0) { // If available flips are exhausted
                if (nums[left] == 0) {
                    k++; // Return one flip to the available pool
                }
                left++; // Shrink the window from the left
            }
            
            maxConsecutiveOnes = max(maxConsecutiveOnes, right - left + 1);
        }
        
        return maxConsecutiveOnes-1;
    }
};
