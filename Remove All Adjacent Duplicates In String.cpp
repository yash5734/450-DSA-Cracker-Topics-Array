class Solution {
public:
    string removeDuplicates(string s) {
        int j = 0;
            while(j<s.length()-1){

                if(s.empty()) return s;
                if(s[j]==s[j+1]){
                    s.erase(j,2);
                     j =0;
                }else
                j++;
            }

        
        return s;
    }
};

//---------------fastest approach--------------all test case pass--------


class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i  =0 ;i<s.length();i++){
            if(ans.empty()){
                ans.push_back(s[i]);
            }
            else if(ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }
            else
            ans.push_back(s[i]);
        }
        return ans;
    }
};
