void solve(queue<int> &q){
    
    if(q.empty()){
        return;
    } 
    
    int num = q.front();
    q.pop();
    
    solve(q);
    q.push(num);
}

queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}
