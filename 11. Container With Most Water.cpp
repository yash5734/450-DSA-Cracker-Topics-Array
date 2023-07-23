class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right = height.size()-1;
        int maxArea =0;
        while(left<right){
            int curr = min(height[left],height[right]) * (right-left);
            maxArea = max(maxArea,curr);

            if(height[left]<height[right]){
                left++;
            }else right--;
        }
        return  maxArea;
    }
};
