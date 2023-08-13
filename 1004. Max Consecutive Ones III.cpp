class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0; // Left pointer of the sliding window
        int maxConsecutiveOnes = 0; // Maximum consecutive ones
        
        for (int right = 0; right < n; ++right) { // Right pointer of the sliding window
            if (nums[right] == 0) {
                k--; // Consume one available flip
            }
            
            while (k < 0) { // If available flips are exhausted
                if (nums[left] == 0) {
                    k++; // Return one flip to the available pool
                }
                left++; // Shrink the window from the left
            }
            
            maxConsecutiveOnes = max(maxConsecutiveOnes, right - left + 1);
        }
        
        return maxConsecutiveOnes;
    }
};
