class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int>mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;

        int i=0;
        int j=k;
        int maxi =0;
        int cnt =0;
        for(int i=0;i<k;i++){
            if(mp.find(s[i])!=mp.end()){
                cnt++;
            }
        }
        maxi = max(maxi,cnt);
        int n = s.length();

        while(j<n){
            if(mp.find(s[j-k])!=mp.end()) cnt--;
            if(mp.find(s[j])!=mp.end())cnt++;
            j++;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
