class Solution {
public:
    double fun(vector<int>& piles, int h){
        double sum =0;
        for(int i=0;i<piles.size();i++){
            double val = (double)piles[i]/h;
            sum+=ceil(val);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }

        int left = 1;
        int right = maxi;
        int mid = left+(right-left)/2;

        while(left<=right){
            
            double val = fun(piles,mid);
            if(val<=h){
                right = mid-1;
            }else{
                left = mid+1;
            }

            mid = left+(right-left)/2;
        }
        return left;
    }
};
