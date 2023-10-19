class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length()-1;
        int j=t.length()-1;

        while(i>=0 || j>=0){

            // count # and skip the char acc to no. of times # occurs for string S;
            int count = 0;
            while(i>=0 && (s[i] == '#' || count>0)){
                if(s[i]=='#') count++; // count no of #
                else count--; // skip the character acc to no. of times # occurs

                i--;
            }

            // count # and skip the char acc to no. of times # occurs for string t;
            count = 0;
            while(j>=0 && (t[j] == '#' || count>0)){
                if(t[j]=='#') count++; // count no of #
                else count--; // skip the character acc to no. of times # occurs

                j--;
            }

            // if there is no # then check the string 

            if(i >= 0 && j>=0)
            {
                if(s[i] != t[j])
                    return false;
                else{
                    i--;
                    j--;
                }
            }
            else{
                if(i>=0 || j>=0) return false;//If any of the string gets exausted while other still remains then return false
            }
        }
        return true;
    }
};
