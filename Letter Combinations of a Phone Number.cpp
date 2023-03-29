class Solution {
private:
    void solve(int ind, string digits, string ds, vector<string> &ans, string mapping[]){
        if(ind>=digits.length()){
            ans.push_back(ds);
            return;
        }

        int number = digits[ind]-'0';
        string value = mapping[number];

        for(int i=0;i<value.length();i++){
            // ds.push_back(value[i]); // in c++ if we push the element in string then string treat as a array so we have to pop the element 
            // and if we add the element in string through + operator then we do not pop the element 
            //bcz string is immutable in nature so it passes the copy not original one 
            solve(ind+1,digits,ds+value[i],ans,mapping);
            // ds.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        string ds = "";
        vector<string> ans;
        if(digits.length()==0) return ans;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,ds,ans,mapping);
        return ans;
    }
};
