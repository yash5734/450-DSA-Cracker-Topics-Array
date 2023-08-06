class Solution {
    private:
    int f(int num){
        int sum =0;
        while(num>0){
            int rm = num%10;
            sum += rm*rm;
            num /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int num) {
        set<int>st;
        while(num!=1 && !st.count(num)){
            st.insert(num);
            int temp = f(num);
            num = temp;
        }
        return num == 1;
    }
};
