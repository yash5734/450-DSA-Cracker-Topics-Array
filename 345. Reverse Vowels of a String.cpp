class Solution {
public:
    string reverseVowels(string s) {
        int start =0;
        int end = s.length()-1;
        map<char,int>mp;
        vector<char>v = {'a','e','i','o','u','A','E','I','O','U'};

        for(auto it:v){
            mp[it]++;
        }

        while(start<end){
            if(mp.find(s[start])!=mp.end() && mp.find(s[end])!=mp.end()){   
                swap(s[start++],s[end--]);
            }else{

                if(mp.find(s[start])==mp.end() && mp.find(s[end])==mp.end()){   
                    start++;
                    end--;
                }else if(mp.find(s[start])==mp.end()){
                    start++;
                }else end--;
            }
        }
        return s;
    }
};
