class Solution {
public:
    vector<int> merge(int ar1[], int ar2[], int n){
        int i=0,j=0;
        vector<int>ans;
        while(i<n&&j<n){
            if(ar1[i]<ar2[j]){
                ans.push_back(ar1[i++]);
            }
            else{
              ans.push_back(ar2[j++]);  
            }
        }
        while(i<n){
            ans.push_back(ar1[i++]);
        }
        
        while(j<n){
            ans.push_back(ar2[j++]);
        }
        
        return ans;
    }

    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            
            vector<int> ar3 = merge(ar1,ar2,n);
            int len = ar3.size()/2;
            int sum = ar3[len]+ar3[len-1];
            return sum;
            }
};
