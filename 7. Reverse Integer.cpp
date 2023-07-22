class Solution {
public:
    int reverse(int x) {
        bool flag =false;
        if(x<0) flag = true;
        int num = abs(x);
        long ans = 0;

        while(num>0){
            int lastNUm = num%10;
            ans = ans*10+lastNUm;
            num = num/10;
        }

        if(flag){
            ans = ans-(2*ans);
        }
        if(ans<INT_MIN||ans>INT_MAX) return 0;
        else{
        
        return (int)ans;
        }
    }
};
