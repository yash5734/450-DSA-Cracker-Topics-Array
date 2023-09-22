//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void left(int *arr, int n, int x, int &ans){
        
        int left =0;
        int right = n;
        int mid = left + (right-left)/2;
        while(left<=right){
            if(arr[mid]==x){
                ans = mid;
                right = mid-1;
            } 
            else if(arr[mid]<x)left = mid+1;
            else right = mid-1;
            mid = left + (right-left)/2;
        }
    }
    void right(int *arr, int n, int x, int &ans){
        
        int left =0;
        int right = n;
        int mid = left + (right-left)/2;
        while(left<=right){
            if(arr[mid]==x){
                ans = mid;
                left = mid+1;
            } 
            else if(arr[mid]<x)left = mid+1;
            else right = mid-1;
            mid = left + (right-left)/2;
        }
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int left_ans =-1;
        int right_ans =-1;
        left(arr,n,x,left_ans);
        right(arr,n,x,right_ans);
        
        return {left_ans,right_ans};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
