struct Meeting{
    int start;
    int end;
    int pos;
};
class Solution
{
public:
    
    bool static comparator( Meeting m1,Meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        
        return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
         Meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        
        sort(meet,meet+n,comparator);
        
        int limit = meet[0].end;
        vector<int>ans;
        ans.push_back(meet[0].pos);
        for(int i=1;i<n;i++){
            if(meet[i].start>limit){
                limit = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }
        
        return ans.size();
        
    }
};
