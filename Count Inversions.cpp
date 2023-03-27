//*********************BRUTE-CASE***************************

long long int inversionCount(long long a[], long long n)
    {
        int c=0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(a[i]>a[j]) c++;
            }
        }
        return c;
    }
    
