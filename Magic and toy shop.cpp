class Solution{   
public:
    int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
    {
        vector<int>reduce;
        int sum1=0;
        int sum2=0;
        int diff =0;
        for(int i=0;i<n;i++){
            sum1+=price[i];
            sum2+=magical_price[i];
            diff = price[i]-magical_price[i];
            //  cout<<diff<<" ";
            reduce.push_back(diff);
        }
        if(sum1<=m) return 0;
        if(sum2>m) return -1;
        
        // for(int i=0;i<n;i++){
        //     cout<<reduce[i]<<" ";
        // }
        
        sort(reduce.begin(),reduce.end());
        reverse(reduce.begin(),reduce.end());
        int left = sum1-m;
        // cout<<left<<endl;
        int temp =0;
        for(int i=0;i<n;i++){
            if(left > 0){
            left = left- reduce[i];
            // cout<<left<<" ";
            temp++;
            }
        }
        return temp;
        
    }
};
