void segregateElements(int a[],int n)
    {
        int i=0;
        vector<int> temp;
        while(i<n){
            if(a[i]>=0)
            temp.push_back(a[i]);
            ++i;
        }
        i=0;
        while(i<n){
            if(a[i]<0)
            temp.push_back(a[i]);
            ++i;
        }
        for(int i=0;i<n;++i){
            a[i] = temp[i];
        }
    }
