void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

void fun(queue<int> &q,int len){
    if(q.empty() || len==0){
        return;
    }
    
    int temp = q.front();
    q.pop();
    fun(q,len-1);
    q.push(temp);
}

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int n = q.size();
    
    reverse(q);
    
    int len = n-k;
    fun(q,len);
    return q;
}
