class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";

        if(!numerator) return "0";

        if(numerator>0  ^ denominator>0){
            ans+='-';
        }

        long num = labs(numerator);
        long den = labs(denominator);

        ans+=to_string((num/den));
        long rem = num%den;

        if(rem == 0) return ans;
        ans+='.';
        unordered_map<long,long>mp;

        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                ans.insert(mp[rem],"(");
                ans+=')';
                break;
            }
            else{
                mp[rem] = ans.length();
                rem*=10;
                int q = rem/den;
                rem = rem%den;

                ans+=to_string(q);
            }
        }
        return ans;
    }
};
