class Solution {
    private:
    bool possible(vector<int>& nums, int threshold,int t){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            float dev = (float)nums[i]/t;
            int temp = ceil(dev);
            sum+=temp; 
        }
        cout<<sum<<endl;
        return sum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start =1;
        int end = *max_element(nums.begin(),nums.end());
        

        int mid = start+(end-start)/2;

        while(start<end){
            if(possible(nums,threshold,mid)){
                end = mid;
            }else start = mid+1;

            mid = start+(end-start)/2;
        }
        return start;
    }
};
