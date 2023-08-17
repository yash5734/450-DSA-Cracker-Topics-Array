class Solution {
public:
    string removeStars(string s) {
        string str = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == '*'){
                str.pop_back();
                continue;
            }
            str+=s[i];
        }
        return str;
    }
};
