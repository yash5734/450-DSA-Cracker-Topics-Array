class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> s;
        s.push(-1);
        vector<int> a(n);
        for(int i = n-1 ;i >= 0; i--){
            
                while(arr[i]<=s.top()){
                    s.pop();
                }
                a[i] = s.top();
                s.push(arr[i]);
            }
        return a;
    } 
};
