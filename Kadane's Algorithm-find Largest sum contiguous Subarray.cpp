 long long maxSubarraySum(int arr[], int n){
        
       
        int cur_sum =0;
        int max_sum =INT_MIN;
        for(int i=0;i<n;++i){
            cur_sum += arr[i];
            if(cur_sum>max_sum){
                max_sum = cur_sum;
            }
            if(cur_sum<0){
                cur_sum =0;
            }
        }
        return max_sum;
        
    }
