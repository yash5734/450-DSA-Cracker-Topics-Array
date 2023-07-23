class Solution {
    private:
    bool check(int ind,string str1, string str2){
        int k=0;
        for(int i=ind;i<ind+str2.length();i++){
            if(str1[i]!=str2[k++]) return false;
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        
        for(int i=0;i<haystack.length();i++){
            if(haystack[i] == needle[0]){
                if(check(i,haystack,needle)){
                    return i;
                }
            }
        }
        return -1;
    }
};
