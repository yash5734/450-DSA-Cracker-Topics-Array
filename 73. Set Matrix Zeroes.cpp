class Solution {
    private:
    void f(int r, int c, int n, int m, vector<vector<int>>& matrix){
        for(int i=0;i<m;i++){
            matrix[r][i] = 0;
        }
        for(int i=0;i<n;i++){
            matrix[i][c] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int,pair<int,int>>mp;
        int k=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(matrix[i][j]==0){
                    mp[k++]={i,j};
                }
            }
        }

        for(auto it:mp){
            f(it.second.first,it.second.second,n,m,matrix);
        }
        

    }
};
