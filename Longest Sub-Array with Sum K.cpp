class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        int sum = 0;
        int maxLen = 0;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            
            sum+=a[i]; // sum the number
            
            if(sum == k){
                maxLen = max(maxLen,i+1); // if sum = k then store the max length
            }
            
            int rem = sum - k; // part of the array to check weather it is present in the hashmap 
            
            if(mpp.find(rem) != mpp.end()){ // if it present then except that part
                int len = i-mpp[rem];       // remaing part will be = k and take the lenght;
                maxLen = max(len,maxLen);
            }
            
            if(mpp.find(sum) == mpp.end()){ // if sum is not present in hashmap then insert the sum
                mpp[sum] = i;   // if the sum is already present is haskmap then we can not update
            }
                
        }
        
        return maxLen;
    } 

};
