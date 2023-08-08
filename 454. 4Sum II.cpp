class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();
        int n4 = nums4.size();
        unordered_map<int,int> mp;

        // Count occurrences of sums from nums3 and nums4
        for (int i = 0; i < n3; i++) {
            for (int j = 0; j < n4; j++) {
                mp[nums3[i] + nums4[j]]++;
            }
        }

        int cnt = 0;

        // Check sums of nums1 and nums2 against the precalculated sums
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int target = -1 * (nums1[i] + nums2[j]);
                if (mp.find(target) != mp.end()) {
                    cnt += mp[target];
                }
            }
        }

        return cnt;
    }
};
