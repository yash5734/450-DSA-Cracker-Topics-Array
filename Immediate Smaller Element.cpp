class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    stack<int>s;
	    s.push(-1);
	    for(int i=n-1;i>=0;i--){
	        if(arr[i]>s.top()){
	            int temp = arr[i];
	            arr[i] = s.top();
	            s.pop();
	            s.push(temp);
	        }
	        else{
	            int temp  = arr[i];
	            arr[i]  = -1;
	            s.pop();
	            s.push(temp);
	        }
	    }
	}

};
