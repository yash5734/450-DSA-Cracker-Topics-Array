#include <bits/stdc++.h> 

void solve(stack<int>& s,int size, int count,int key){

    //base case
    if(count==size){
        s.push(key);
        return  ;
    }

    int temp = s.top();
    s.pop();

    // recursive call;

    solve(s,size,count+1,key);
    s.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    int count = 0;
    int size = myStack.size();
    solve(myStack,size,count,x);

    return myStack;
}
