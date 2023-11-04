
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int a[], int n) {
	    // code here
	    vector<int>arr;
	    set<int>st;
	    for(int i=0;i<n;i++){
	        st.insert(a[i] *a[i]);
	    }
	    
	    for(auto it:st){
	        arr.push_back(it);
	    }
	    
	    
	    
	    sort(arr.begin(),arr.end());
	    
	    int N = arr.size();
	    
	    for(int i=2;i<N;i++){
	        int start = 0;
	        int end = i-1;
	        
	        while(start<end){
	            if(arr[i] == (arr[start]+arr[end])) return true;
	            else if(arr[i] > (arr[start]+arr[end])){
	                start++;
	            }else end--;
	        }
	    }
	    
	    return false;
	}
};
