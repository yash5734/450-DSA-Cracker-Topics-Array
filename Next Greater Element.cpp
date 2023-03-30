class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        s.push(-1);
        vector<long long>a;
        for(long long i = n-1;i>=0;i--){
            while(arr[i]>=s.top()&& s.top()!=-1 ){
                s.pop();
            }
            a.push_back(s.top());
            s.push(arr[i]);
        }
        reverse(a.begin(),a.end());
        return a;
    }
};
