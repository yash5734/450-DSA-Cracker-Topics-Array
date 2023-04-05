class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        int max = -1;
        for(int i=0;i<nums1.size();i++){
            bool flag = false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    flag = true;
                }
                if(flag){
                    if(nums2[j]>nums1[i]){
                        max = nums2[j];
                        break;
                    }
                    else{
                        max =-1;
                    }
                }
            }
            arr.push_back(max);
        }
        return arr;
    }
};
