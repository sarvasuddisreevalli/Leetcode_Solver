class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                int flag=0;
                if(i>0 && mat[i-1][j]>=mat[i][j]) flag=1; 
                if(flag==0 && i<mat.size()-1 && mat[i+1][j]>=mat[i][j]) flag=1; 
                if(flag==0 && j>0 && mat[i][j-1]>=mat[i][j]) flag=1; 
                if(flag==0 && j<mat[0].size()-1 && mat[i][j+1]>=mat[i][j]) flag=1; 
                if(flag==0) return {i,j};
            }
        }
        return {};
    }
};