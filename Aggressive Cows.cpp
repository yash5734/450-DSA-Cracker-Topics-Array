class Solution {
public:


    bool isPossible(vector<int> &stalls,int k,int mid,int n){
        
        int cowcount = 1;
        int lastcow = stalls[0];
        for(int i =0;i<n;i++){
            if(stalls[i]-lastcow>=mid){
                cowcount++;
                if(cowcount==k) return true;
                lastcow = stalls[i];
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
    sort(stalls.begin(), stalls.end());
        
        int ans = 0;
        int start = 0;
        int end = stalls[n-1];
        int mid = start+(end-start)/2;
        
        while(start<=end){
            
            if(isPossible(stalls,k,mid,n)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
          mid = start+(end-start)/2;   
        }
        
        return ans;
        
    }
};

