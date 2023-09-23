class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        
        long long left = 0;
        long long right = sum;
        
        for(int i=0;i<n;i++){
            right = right - a[i];
            if(left == right) return i+1;
            left = left + a[i];
        }
        return -1;
    }

};
