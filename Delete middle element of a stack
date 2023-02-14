class Solution
{
    public:
    
    void solve(stack<int>&s, int sizeOfStack,int count){
        
        // base case
        if(count==sizeOfStack/2){
            s.pop();
            return ;
        }
        int temp = s.top();
        s.pop();
        
        //recursive call
        solve(s,sizeOfStack,count+1);
        
        s.push(temp);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int count = 0;
        solve(s,sizeOfStack,count);
    }
};
