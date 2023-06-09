//  BRUTE FORCE APPROCH
class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int len =0;
        int ans =0;
        for(int i=0;i<n;i++){
            int curr = arr[i];
            if(curr==0) len=1;
            for(int j=i+1;j<n;j++){
                curr+=arr[j];
                
                if(curr == 0){
                    len = j-i+1;
                }
            }
            // if(curr==0) len  =1;
            ans = max(ans,len);
        }
        return ans;
    }
};
// TC = O(N^2) SC = O(1);


// BETTER APPROCH

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int, int>prefixSum;
        int sum =0;
        int len = 0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                len = max(len,i+1);
            }
            int rem = sum-0;
             if(prefixSum.find(rem)!=prefixSum.end()){
                len = max(len,i-prefixSum[rem]);
            }
            
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum]  =i;
            }
            
        }
        return len;
    }
};

// TC = O(N)
