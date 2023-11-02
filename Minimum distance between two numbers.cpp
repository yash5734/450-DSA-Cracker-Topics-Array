class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int i1=-1, i2=-1;
        int dist=INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i]==x){
                i1=i;
                if(i2!=-1){
                    dist=min(dist, abs(i2-i1));
                }
            }
            else if(a[i]==y){
               i2=i;
                if(i1!=-1){
                    dist=min(dist, abs(i2-i1));
                } 
            }
        }
        
        if(i1==-1 || i2==-1) return -1;
        else return dist;
    }
};
