class Solution {
public:
    string decodeString(string s) {
        string res ="";
        stack<string>chars;
        stack<int>nums;
        int num=0;
        
        for(auto ch:s){
            if(isdigit(ch)){
                num = num*10 + (ch-'0'); 
            }
            else if(ch == '['){
                nums.push(num);
                chars.push(res);

                num =0;
                res = "";
            }
            else if(ch==']'){
                string temp = res;
                res = chars.top();
                chars.pop();
                for(int i=nums.top();i>0;i--){
                    res+=temp;
                }
                nums.pop();
            }
            else{
                res+=ch;
            }
        }
        return res;

    }
};
