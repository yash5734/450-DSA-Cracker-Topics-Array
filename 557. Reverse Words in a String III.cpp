class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string str = "";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == ' '){
                reverse(str.begin(),str.end());
                str+=" ";
                ans+=str;
                str = "";
            }
            if(ch!=' ')
            str+=ch;
        }
        reverse(str.begin(),str.end());
                // str+=" ";
                ans+=str;
        // ans.pop_back();
        return ans;

    }
};
